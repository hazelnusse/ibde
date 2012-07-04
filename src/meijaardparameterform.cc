#include "meijaardparameterform.h"

#include <QDoubleValidator>
#include <QGridLayout>
#include <QLabel>
// #include <QLineEdit>
#include <QDoubleSpinBox>

MeijaardParameterForm::MeijaardParameterForm(QWidget *parent)
  : QWidget(parent)
{
  createSpinBoxes();
  createGridLayout();
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
} // MeijaardParameterForm

void MeijaardParameterForm::createSpinBoxes()
{
  w = new QDoubleSpinBox;

  c = new QDoubleSpinBox;

  lambda = new QDoubleSpinBox;

  rR = new QDoubleSpinBox;

  mR = new QDoubleSpinBox;

  IRxx = new QDoubleSpinBox;

  IRyy = new QDoubleSpinBox;

  xB = new QDoubleSpinBox;

  zB = new QDoubleSpinBox;

  mB = new QDoubleSpinBox;

  IBxx = new QDoubleSpinBox;

  IByy = new QDoubleSpinBox;

  IBzz = new QDoubleSpinBox;

  IBxz = new QDoubleSpinBox;

  xH = new QDoubleSpinBox;

  zH = new QDoubleSpinBox;

  mH = new QDoubleSpinBox;

  IHxx = new QDoubleSpinBox;

  IHyy = new QDoubleSpinBox;

  IHzz = new QDoubleSpinBox;

  IHxz = new QDoubleSpinBox;

  rF = new QDoubleSpinBox;

  mF = new QDoubleSpinBox;

  IFxx = new QDoubleSpinBox;
  
  IFyy = new QDoubleSpinBox;
  
  g = new QDoubleSpinBox;
  g->setValue(9.81);
} // createSpinBoxes()

void MeijaardParameterForm::createGridLayout()
{
  QGridLayout *gl = new QGridLayout(this);

  gl->addWidget(new QLabel("w"), 0, 0, Qt::AlignRight);
  gl->addWidget(w, 0, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 0, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("c"), 1, 0, Qt::AlignRight);
  gl->addWidget(c, 1, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 1, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("lambda"), 2, 0, Qt::AlignRight);
  gl->addWidget(lambda, 2, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("rad"), 2, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("rR"), 3, 0, Qt::AlignRight);
  gl->addWidget(rR, 3, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 3, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("mR"), 4, 0, Qt::AlignRight);
  gl->addWidget(mR, 4, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg"), 4, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IRxx"), 5, 0, Qt::AlignRight);
  gl->addWidget(IRxx, 5, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 5, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IRyy"), 6, 0, Qt::AlignRight);
  gl->addWidget(IRyy, 6, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 6, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("xB"), 7, 0, Qt::AlignRight);
  gl->addWidget(xB, 7, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 7, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("zB"), 8, 0, Qt::AlignRight);
  gl->addWidget(zB, 8, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 8, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("mB"), 9, 0, Qt::AlignRight);
  gl->addWidget(mB, 9, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg"), 9, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IBxx"), 10, 0, Qt::AlignRight);
  gl->addWidget(IBxx, 10, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 10, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IByy"), 11, 0, Qt::AlignRight);
  gl->addWidget(IByy, 11, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 11, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IBzz"), 12, 0, Qt::AlignRight);
  gl->addWidget(IBzz, 12, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 12, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IBxz"), 13, 0, Qt::AlignRight);
  gl->addWidget(IBxz, 13, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 13, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("xH"), 14, 0, Qt::AlignRight);
  gl->addWidget(xH, 14, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 14, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("zH"), 15, 0, Qt::AlignRight);
  gl->addWidget(zH, 15, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 15, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("mH"), 16, 0, Qt::AlignRight);
  gl->addWidget(mH, 16, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg"), 16, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IHxx"), 17, 0, Qt::AlignRight);
  gl->addWidget(IHxx, 17, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 17, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IHyy"), 18, 0, Qt::AlignRight);
  gl->addWidget(IHyy, 18, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 18, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IHzz"), 19, 0, Qt::AlignRight);
  gl->addWidget(IHzz, 19, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 19, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IHxz"), 20, 0, Qt::AlignRight);
  gl->addWidget(IHxz, 20, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 20, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("rF"), 21, 0, Qt::AlignRight);
  gl->addWidget(rF, 21, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 21, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("mF"), 22, 0, Qt::AlignRight);
  gl->addWidget(mF, 22, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg"), 22, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IFxx"), 23, 0, Qt::AlignRight);
  gl->addWidget(IFxx, 23, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 23, 2, Qt::AlignLeft);

  gl->addWidget(new QLabel("IFyy"), 24, 0, Qt::AlignRight);
  gl->addWidget(IFyy, 24, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 24, 2, Qt::AlignLeft);
  
  gl->addWidget(new QLabel("gravity"), 25, 0, Qt::AlignRight);
  gl->addWidget(g, 25, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("m/s^2"), 25, 2, Qt::AlignLeft);

  //gl->setSpacing(0);
} // createGridLayout
