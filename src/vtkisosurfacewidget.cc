#include <vtkProperty.h>

#include "vtkisosurfacewidget.h"
#include "MeijaardBikeParameters.h"
#include "ConvertBikeParameters.h"
#include "BikeHolonomic.h"

vtkIsosurfaceWidget::vtkIsosurfaceWidget(BikeParameters<double> & bike, QWidget * parent, Qt::WFlags f)
  : QVTKWidget(parent, f), bike_(bike)
{
  // Create the implicit function to sample and set the bike parameters
  configurationSurface = vtkSmartPointer<vtkHolonomicConstraint>::New();
  configurationSurface->SetBike(&bike_);

  // Determine the range of pitch
  double pitchminmax[2];
  ComputePitchBounds(pitchminmax);

  // Sample the function
  sampleFunction = vtkSmartPointer<vtkSampleFunction>::New();
  sampleFunction->SetSampleDimensions(50, 50, 50);
  sampleFunction->SetImplicitFunction(configurationSurface);
  sampleFunction->SetModelBounds(-M_PI/2.0, M_PI/2.0, pitchminmax[0], pitchminmax[1], -M_PI, M_PI);

  // Create the zero isosurface
  contourFilter = vtkSmartPointer<vtkContourFilter>::New();
  contourFilter->SetInputConnection(sampleFunction->GetOutputPort());
  contourFilter->Update();// needed?
  RefineConfigurationSurface();

  // Map the contours to graphical primitives
  contourMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  contourMapper->SetInputConnection(contourFilter->GetOutputPort());
  contourMapper->SetScalarRange(0.0, 1.2);
 
  // Create an actor for the contours
  contourActor = vtkSmartPointer<vtkActor>::New();
  contourActor->SetMapper(contourMapper);

  // Create axes
  axesActor = vtkSmartPointer<vtkAxesActor>::New();
  axesActor->SetShaftTypeToCylinder();
  axesActor->AxisLabelsOff();

  // Create outline
  outlineFilter = vtkSmartPointer<vtkOutlineFilter>::New();
  outlineFilter->SetInputConnection(contourFilter->GetOutputPort());

  // Map it to graphics primitives
  outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  outlineMapper->SetInputConnection(outlineFilter->GetOutputPort());

  //  // Create an actor for it
  outlineActor = vtkSmartPointer<vtkActor>::New();
  outlineActor->SetMapper(outlineMapper);
  outlineActor->GetProperty()->SetColor(0, 0, 0);

  // Create a renderer and add all actors
  renderer = vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(contourActor);
  renderer->AddActor(axesActor);
  renderer->AddActor(outlineActor);
  renderer->SetBackground(1, 1, 1); // Background color white

  renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  SetRenderWindow(renderWindow);
} // vtkIsosurfaceWidget()

void vtkIsosurfaceWidget::RefineConfigurationSurface()
{
  vtkPoints * const points = contourFilter->GetOutput()->GetPoints();
  const vtkIdType N = points->GetNumberOfPoints();
  for (vtkIdType i = 0; i < N; ++i) {
    double lps[3];
    points->GetPoint(i, lps);
    RefineLeanPitchSteer(bike_, 10, lps);
    points->SetPoint(i, lps);
  }
} // RefineConfigurationSurface()

void vtkIsosurfaceWidget::UpdateConfigurationSurface()
{
  double pitchbounds[2];
  ComputePitchBounds(pitchbounds);
  sampleFunction->SetModelBounds(-M_PI/2.0, M_PI/2.0, pitchbounds[0], pitchbounds[1], -M_PI, M_PI);
  sampleFunction->Modified();
  configurationSurface->Modified();
  contourFilter->Update();// needed?
  RefineConfigurationSurface();
  renderWindow->Render();
} // UpdateConfigurationSurface()

void vtkIsosurfaceWidget::ComputePitchBounds(double angles[2])
{
    double referencepitch[2], middle, delta;
    ReferencePitchAngles(bike_, referencepitch);
    middle = (referencepitch[0] + referencepitch[1])/2.0;
    delta = referencepitch[1] - referencepitch[0];
    
    double factor = .75;
    angles[0] = middle - delta*factor;
    angles[1] = middle + delta*factor;
} // ComputePitchBounds()
