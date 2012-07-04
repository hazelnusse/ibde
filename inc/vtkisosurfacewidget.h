#ifndef VTKISOSURFACEWIDGET_H
#define VTKISOSURFACEWIDGET_H

#include <vtkActor.h>
#include <vtkAxesActor.h>
#include <vtkContourFilter.h>
#include <vtkOutlineFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSampleFunction.h>
#include <vtkSmartPointer.h>
#include <QVTKWidget.h>

#include "vtkHolonomicConstraint.h"
#include "BikeParameters.h"

class vtkIsosurfaceWidget : public QVTKWidget {
  Q_OBJECT
 public:
  vtkIsosurfaceWidget(BikeParameters<double> & bp, QWidget * parent = 0, Qt::WFlags f = 0);

 public slots:
  void UpdateConfigurationSurface();

 private:
  void ComputePitchBounds(double angles[2]);
  void RefineConfigurationSurface();

  BikeParameters<double> & bike_;
  vtkSmartPointer<vtkHolonomicConstraint> configurationSurface;
  vtkSmartPointer<vtkSampleFunction> sampleFunction;
  vtkSmartPointer<vtkContourFilter> contourFilter;
  vtkSmartPointer<vtkPolyDataMapper> contourMapper;
  vtkSmartPointer<vtkActor> contourActor;
  vtkSmartPointer<vtkAxesActor> axesActor;
  vtkSmartPointer<vtkOutlineFilter> outlineFilter;
  vtkSmartPointer<vtkPolyDataMapper> outlineMapper;
  vtkSmartPointer<vtkActor> outlineActor;

  vtkSmartPointer<vtkRenderer> renderer;
  vtkSmartPointer<vtkRenderWindow> renderWindow;
};
#endif // VTKISOSURFACEWIDGET_H
