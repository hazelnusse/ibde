#ifndef PARAMETERWIDGET_H
#define PARAMETERWIDGET_H

#include <QWidget>
#include <BikeParameters.h>

class QVBoxLayout;

class ParameterWidget: public QWidget
{
    Q_OBJECT
  public:
    enum ParameterSet {Gyrostat, Meijaard};
    explicit ParameterWidget(ParameterSet p, BikeParameters<double> & bp, QWidget * parent = 0);

  signals:
    void ConstraintParametersChanged();
    void ParametersChanged();

  private slots:

  private:
    void initializeLayouts(ParameterSet p);
    void buildConnections();

    QVBoxLayout *vbox;
    QWidget * ParameterForm;
    BikeParameters<double> & bp_;
};
#endif // PARAMETERWIDGET_H
