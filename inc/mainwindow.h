#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "parameterwidget.h"
#include "BikeParameters.h"

class QVTKWidget;

class MainWindow : public QMainWindow {
  Q_OBJECT

  public:
    explicit MainWindow(ParameterWidget::ParameterSet p = ParameterWidget::Gyrostat);

  private slots:

  private:
    ParameterWidget * pWidget;
    QVTKWidget * vtkWidget;
    BikeParameters<double> bike;
};
#endif
