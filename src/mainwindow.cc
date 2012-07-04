#include "mainwindow.h"
#include <QDebug>
#include <QDockWidget>
#include "vtkisosurfacewidget.h"
#include "ConvertBikeParameters.h"
#include "MeijaardBikeParameters.h"

MainWindow::MainWindow(ParameterWidget::ParameterSet p)
{
  MeijaardBikeParameters<double> bp = BenchmarkParameters<double>();
  bike = ConvertBikeParameters(bp);
  pWidget = new ParameterWidget(p, bike, this);

  QDockWidget *dockWidget = new QDockWidget(tr("Parameters"), this);
  dockWidget->setFeatures(QDockWidget::DockWidgetFloatable |
                          QDockWidget::DockWidgetMovable);
  dockWidget->setWidget(pWidget);
  dockWidget->setFloating(true);
  
  vtkWidget = new vtkIsosurfaceWidget(bike, this);
  connect(pWidget, SIGNAL(ConstraintParametersChanged()),
          vtkWidget, SLOT(UpdateConfigurationSurface()));
  setCentralWidget(vtkWidget);
}
