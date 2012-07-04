#include "parameterwidget.h"
#include "gyrostatparameterform.h"
#include "meijaardparameterform.h"

#include <QVBoxLayout>

ParameterWidget::ParameterWidget(ParameterSet p, BikeParameters<double> & bp, QWidget *parent)
  : QWidget(parent), bp_(bp)
{
  initializeLayouts(p);
  buildConnections();
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void ParameterWidget::initializeLayouts(ParameterSet p)
{
  vbox = new QVBoxLayout;

  if (p == Gyrostat)
    ParameterForm = new GyrostatParameterForm(bp_, this); 
  else
    ParameterForm = new MeijaardParameterForm(this);

  ParameterForm->show();
  vbox->addWidget(ParameterForm);

  setLayout(vbox);
}

void ParameterWidget::buildConnections()
{
  connect(ParameterForm, SIGNAL(ConstraintParametersChanged()),
          this, SIGNAL(ConstraintParametersChanged()));
  connect(ParameterForm, SIGNAL(ParametersChanged()),
          this, SIGNAL(ParametersChanged()));
}
