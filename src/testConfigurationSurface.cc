#include <vector>
#include <algorithm>

#include <vtkAxesActor.h>
#include <vtkCaptionActor2D.h>
#include <vtkTextProperty.h>
#include <vtkCellArray.h>
#include <vtkDoubleArray.h>
#include <vtkFloatArray.h>
#include <vtkSmartPointer.h>
#include <vtkSampleFunction.h>
#include <vtkContourFilter.h>
#include <vtkOutlineFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkPointData.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkImageData.h>
 
#include "vtkHolonomicConstraint.h"
#include "MeijaardBikeParameters.h"
#include "ConvertBikeParameters.h"
#include "BikeParameters.h"
#include "BikeHolonomic.h"

#define VTK_CREATE(type, name)\
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

vtkActor * CreateOutline(vtkSmartPointer<vtkSampleFunction> s);
vtkActor * CreateConstraintSurface(vtkSmartPointer<vtkSampleFunction> s, BikeParameters<double> *);
void RenderAndInteract(std::vector<vtkSmartPointer<vtkActor>> &actors);

template <typename T>
static bool abs_compare(T a, T b)
{
    return (std::fabs(a) < std::fabs(b));
}

int main(int, char *[])
{
  BikeParameters<double> * bike = new
    BikeParameters<double>(ConvertBikeParameters(BenchmarkParameters<double>()));

  // Create the implicit function to sample
  VTK_CREATE(vtkHolonomicConstraint, configurationSurface);
  configurationSurface->SetBike(bike);

  // Sample the function
  VTK_CREATE(vtkSampleFunction, sample);
  sample->SetOutputScalarTypeToDouble();
  sample->SetSampleDimensions(50, 50, 50);
  sample->SetImplicitFunction(configurationSurface);

  {
    double referencepitch[2], middle, delta;
    ReferencePitchAngles(*bike, referencepitch);
    middle = (referencepitch[0] + referencepitch[1])/2.0;
    delta = referencepitch[1] - referencepitch[0];
    double lps[3] = {0.0, referencepitch[0], 0.0};
    
    std::cout << "q2[0] = " << referencepitch[0] << std::endl;

    std::cout << "fw height: " << FrontContactHeight(lps, *bike) << std::endl;
    std::cout << "q2[1] = " << referencepitch[1] << std::endl;
    lps[1] = referencepitch[1];
    std::cout << "fw height: " << FrontContactHeight(lps, *bike) << std::endl;
    std::cout << "midpoint = " << middle << std::endl;
    std::cout << "delta = " << delta << std::endl;
    // TODO:  Figure out 
    sample->SetModelBounds(-M_PI/2.0, M_PI/2.0, middle - delta/1.9, middle + delta/1.9, -M_PI, M_PI);
  }

  // Create the holonomic constraint surface
  vtkSmartPointer<vtkActor> contourActor(CreateConstraintSurface(sample, bike));
 
  // Create a box around the function to indicate the sampling volume
  vtkSmartPointer<vtkActor> outlineActor(CreateOutline(sample));
 
  // Create renderer, window, and interactor, render all actors
  std::vector<vtkSmartPointer<vtkActor>> actors {contourActor, outlineActor};
  RenderAndInteract(actors);
  delete bike;
} // main()

vtkActor * CreateOutline(vtkSmartPointer<vtkSampleFunction> s)
{
  // Create outline
  VTK_CREATE(vtkOutlineFilter, outline);
  outline->SetInputConnection(s->GetOutputPort());

  // Map it to graphics primitives
  VTK_CREATE(vtkPolyDataMapper, outlineMapper);
  outlineMapper->SetInputConnection(outline->GetOutputPort());

  // Create an actor for it
  vtkActor * outlineActor = vtkActor::New();
  outlineActor->SetMapper(outlineMapper);
  outlineActor->GetProperty()->SetColor(0, 0, 0);

  return outlineActor;
} // CreateOutline()

vtkActor * CreateConstraintSurface(vtkSmartPointer<vtkSampleFunction> s, BikeParameters<double> *b)
{
  // Create the 0 isosurface
  VTK_CREATE(vtkContourFilter, contours);
  // contours->SetOutputPointsPrecision(vtkAlgorithm::DOUBLE_PRECISION);
  contours->SetInputConnection(s->GetOutputPort());
  contours->GenerateValues(1, 0.0, 0.0);

  contours->Update();

  // contours->GetOutput()->Print(std::cout);
  vtkPoints * points = contours->GetOutput()->GetPoints();

  std::vector<double> fw_height;
  for (vtkIdType i = 0; i < points->GetNumberOfPoints(); ++i) {
    double lps[3];
    points->GetPoint(i, lps);
    fw_height.push_back(FrontContactHeight(lps, *b));
  }
  std::vector<double>::iterator result;
  result = std::max_element(fw_height.begin(), fw_height.end(), abs_compare<double>);
  std::cout << "Max (absolute) distance from ground plane: "
    << fw_height[std::distance(fw_height.begin(), result)] << std::endl;


 
  // Map the contours to graphical primitives
  VTK_CREATE(vtkPolyDataMapper, contourMapper);
  contourMapper->SetInputConnection(contours->GetOutputPort());
  // Not sure what this does
  // contourMapper->SetScalarRange(0.0, 1.2);
 
  // Create an actor for the contours
  vtkActor * contourActor = vtkActor::New();
  contourActor->SetMapper(contourMapper);
  return contourActor;
} // CreateConstraintSurface()

void RenderAndInteract(std::vector<vtkSmartPointer<vtkActor>> &actors)
{
  VTK_CREATE(vtkRenderer, renderer);

  for (auto actor : actors)
    renderer->AddActor(actor);

  VTK_CREATE(vtkAxesActor, axes);
  axes->SetShaftTypeToCylinder();
  axes->SetXAxisLabelText("l");
  axes->SetYAxisLabelText("p");
  axes->SetZAxisLabelText("s");
  axes->GetXAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(0,0,0);
  axes->GetXAxisCaptionActor2D()->GetCaptionTextProperty()->SetFontSize(8);
  axes->GetXAxisCaptionActor2D()->GetCaptionTextProperty()->ShadowOff();
  axes->GetYAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(0,0,0);
  axes->GetYAxisCaptionActor2D()->GetCaptionTextProperty()->SetFontSize(8);
  axes->GetYAxisCaptionActor2D()->GetCaptionTextProperty()->ShadowOff();
  axes->GetZAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(0,0,0);
  axes->GetZAxisCaptionActor2D()->GetCaptionTextProperty()->SetFontSize(8);
  axes->GetZAxisCaptionActor2D()->GetCaptionTextProperty()->ShadowOff();
  // axes->SetTotalLength(0.3, 0.3, 0.3);
  renderer->AddActor(axes);

  renderer->SetBackground(1, 1, 1); // Background color white
 
  VTK_CREATE(vtkRenderWindow, renderWindow);
  renderWindow->AddRenderer(renderer);

  VTK_CREATE(vtkRenderWindowInteractor, interactor);
  interactor->SetRenderWindow(renderWindow);
 
  renderWindow->Render();
  interactor->Start();
} // RenderAndInteract()
