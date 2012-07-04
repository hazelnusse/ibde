#include "gyrostatparameterform.h"

#include <QGridLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QDebug>

GyrostatParameterForm::GyrostatParameterForm(BikeParameters<double> & bp, QWidget *parent)
  : QWidget(parent), bp_(bp)
{
  createSpinBoxes();
  createGridLayout();
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void GyrostatParameterForm::createSpinBoxes()
{
  Ixx_R = createSpinBox(bp_.rear.gyrostat.I.xx, 0.0, 100.0, 0.01);
  connect(Ixx_R, SIGNAL(valueChanged(double)), this, SLOT(setIxx_R(double)));

  Iyy_R = createSpinBox(bp_.rear.gyrostat.I.yy, 0.0, 100.0, 0.01);
  connect(Iyy_R, SIGNAL(valueChanged(double)), this, SLOT(setIyy_R(double)));

  Izz_R = createSpinBox(bp_.rear.gyrostat.I.zz, 0.0, 100.0, 0.01);
  connect(Izz_R, SIGNAL(valueChanged(double)), this, SLOT(setIzz_R(double)));

  Ixy_R = createSpinBox(bp_.rear.gyrostat.I.xy, -100.0, 100.0, 0.01);
  connect(Ixy_R, SIGNAL(valueChanged(double)), this, SLOT(setIxy_R(double)));

  Iyz_R = createSpinBox(bp_.rear.gyrostat.I.yz, -100.0, 100.0, 0.01);
  connect(Iyz_R, SIGNAL(valueChanged(double)), this, SLOT(setIyz_R(double)));

  Ixz_R = createSpinBox(bp_.rear.gyrostat.I.xz, -100.0, 100.0, 0.01);
  connect(Ixz_R, SIGNAL(valueChanged(double)), this, SLOT(setIxz_R(double)));

  J_R = createSpinBox(bp_.rear.gyrostat.J, 0.0, 100.0, 0.01);
  connect(J_R, SIGNAL(valueChanged(double)), this, SLOT(setJ_R(double)));

  m_R = createSpinBox(bp_.rear.gyrostat.m, 0.0, 100.0, 0.01);
  connect(m_R, SIGNAL(valueChanged(double)), this, SLOT(setm_R(double)));

  a_R = createSpinBox(bp_.rear.a, 0.0, 10.0, 0.01);
  connect(a_R, SIGNAL(valueChanged(double)), this, SLOT(seta_R(double)));

  b_R = createSpinBox(bp_.rear.b, 0.0, 10.0, 0.01);
  connect(b_R, SIGNAL(valueChanged(double)), this, SLOT(setb_R(double)));

  d_R = createSpinBox(bp_.rear.gyrostat.d, -10.0, 10.0, 0.01);
  connect(d_R, SIGNAL(valueChanged(double)), this, SLOT(setd_R(double)));

  e_R = createSpinBox(bp_.rear.gyrostat.e, -10.0, 10.0, 0.01);
  connect(e_R, SIGNAL(valueChanged(double)), this, SLOT(sete_R(double)));

  f_R = createSpinBox(bp_.rear.gyrostat.f, -10.0, 10.0, 0.01);
  connect(f_R, SIGNAL(valueChanged(double)), this, SLOT(setf_R(double)));

  g_R = createSpinBox(bp_.rear.g, -10.0, 10.0, 0.01);
  connect(g_R, SIGNAL(valueChanged(double)), this, SLOT(setg_R(double)));

  h_R = createSpinBox(bp_.rear.h, -10.0, 10.0, 0.01);
  connect(h_R, SIGNAL(valueChanged(double)), this, SLOT(seth_R(double)));

  Ixx_F = createSpinBox(bp_.front.gyrostat.I.xx, 0.0, 100.0, 0.01);
  connect(Ixx_F, SIGNAL(valueChanged(double)), this, SLOT(setIxx_F(double)));

  Iyy_F = createSpinBox(bp_.front.gyrostat.I.yy, 0.0, 100.0, 0.01);
  connect(Iyy_F, SIGNAL(valueChanged(double)), this, SLOT(setIyy_F(double)));

  Izz_F = createSpinBox(bp_.front.gyrostat.I.zz, 0.0, 100.0, 0.01);
  connect(Izz_F, SIGNAL(valueChanged(double)), this, SLOT(setIzz_F(double)));

  Ixy_F = createSpinBox(bp_.front.gyrostat.I.xy, -100.0, 100.0, 0.01);
  connect(Ixy_F, SIGNAL(valueChanged(double)), this, SLOT(setIxy_F(double)));

  Iyz_F = createSpinBox(bp_.front.gyrostat.I.yz, -100.0, 100.0, 0.01);
  connect(Iyz_F, SIGNAL(valueChanged(double)), this, SLOT(setIyz_F(double)));

  Ixz_F = createSpinBox(bp_.front.gyrostat.I.xz, -100.0, 100.0, 0.01);
  connect(Ixz_F, SIGNAL(valueChanged(double)), this, SLOT(setIxz_F(double)));

  J_F = createSpinBox(bp_.front.gyrostat.J, 0.0, 100.0, 0.01);
  connect(J_F, SIGNAL(valueChanged(double)), this, SLOT(setJ_F(double)));

  m_F = createSpinBox(bp_.front.gyrostat.m, 0.0, 100.0, 0.01);
  connect(m_F, SIGNAL(valueChanged(double)), this, SLOT(setm_F(double)));

  a_F = createSpinBox(bp_.front.a, 0.0, 10.0, 0.01);
  connect(a_F, SIGNAL(valueChanged(double)), this, SLOT(seta_F(double)));

  b_F = createSpinBox(bp_.front.b, 0.0, 10.0, 0.01);
  connect(b_F, SIGNAL(valueChanged(double)), this, SLOT(setb_F(double)));

  d_F = createSpinBox(bp_.front.gyrostat.d, -10.0, 10.0, 0.01);
  connect(d_F, SIGNAL(valueChanged(double)), this, SLOT(setd_F(double)));

  e_F = createSpinBox(bp_.front.gyrostat.e, -10.0, 10.0, 0.01);
  connect(e_F, SIGNAL(valueChanged(double)), this, SLOT(sete_F(double)));

  f_F = createSpinBox(bp_.front.gyrostat.f, -10.0, 10.0, 0.01);
  connect(f_F, SIGNAL(valueChanged(double)), this, SLOT(setf_F(double)));

  g_F = createSpinBox(bp_.front.g, -10.0, 10.0, 0.01);
  connect(g_F, SIGNAL(valueChanged(double)), this, SLOT(setg_F(double)));

  h_F = createSpinBox(bp_.front.h, -10.0, 10.0, 0.01);
  connect(h_F, SIGNAL(valueChanged(double)), this, SLOT(seth_F(double)));

  ls = createSpinBox(bp_.ls, -10.0, 10.0, 0.01);
  connect(ls, SIGNAL(valueChanged(double)), this, SLOT(setls(double)));

  g = createSpinBox(bp_.g, 0.0, 100.0, 0.01);
  connect(g, SIGNAL(valueChanged(double)), this, SLOT(setg(double)));
}

void GyrostatParameterForm::createGridLayout()
{
  QGridLayout *gl = new QGridLayout(this);
  gl->addWidget(new QLabel("Rear"), 0, 1, Qt::AlignCenter);
  gl->addWidget(new QLabel("Front"), 0, 2, Qt::AlignCenter);

  gl->addWidget(new QLabel("Ixx"), 1, 0, Qt::AlignRight);
  gl->addWidget(Ixx_R, 1, 1, Qt::AlignCenter);
  gl->addWidget(Ixx_F, 1, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 1, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("Iyy"), 2, 0, Qt::AlignRight);
  gl->addWidget(Iyy_R, 2, 1, Qt::AlignCenter);
  gl->addWidget(Iyy_F, 2, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 2, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("Izz"), 3, 0, Qt::AlignRight);
  gl->addWidget(Izz_R, 3, 1, Qt::AlignCenter);
  gl->addWidget(Izz_F, 3, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 3, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("Ixy"), 4, 0, Qt::AlignRight);
  gl->addWidget(Ixy_R, 4, 1, Qt::AlignCenter);
  gl->addWidget(Ixy_F, 4, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 4, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("Iyz"), 5, 0, Qt::AlignRight);
  gl->addWidget(Iyz_R, 5, 1, Qt::AlignCenter);
  gl->addWidget(Iyz_F, 5, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 5, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("Ixz"), 6, 0, Qt::AlignRight);
  gl->addWidget(Ixz_R, 6, 1, Qt::AlignCenter);
  gl->addWidget(Ixz_F, 6, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 6, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("J"), 7, 0, Qt::AlignRight);
  gl->addWidget(J_R, 7, 1, Qt::AlignCenter);
  gl->addWidget(J_F, 7, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg*m^2"), 7, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("m"), 8, 0, Qt::AlignRight);
  gl->addWidget(m_R, 8, 1, Qt::AlignCenter);
  gl->addWidget(m_F, 8, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("kg"), 8, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("a"), 9, 0, Qt::AlignRight);
  gl->addWidget(a_R, 9, 1, Qt::AlignCenter);
  gl->addWidget(a_F, 9, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 9, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("b"), 10, 0, Qt::AlignRight);
  gl->addWidget(b_R, 10, 1, Qt::AlignCenter);
  gl->addWidget(b_F, 10, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 10, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("d"), 11, 0, Qt::AlignRight);
  gl->addWidget(d_R, 11, 1, Qt::AlignCenter);
  gl->addWidget(d_F, 11, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 11, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("e"), 12, 0, Qt::AlignRight);
  gl->addWidget(e_R, 12, 1, Qt::AlignCenter);
  gl->addWidget(e_F, 12, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 12, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("f"), 13, 0, Qt::AlignRight);
  gl->addWidget(f_R, 13, 1, Qt::AlignCenter);
  gl->addWidget(f_F, 13, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 13, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("g"), 14, 0, Qt::AlignRight);
  gl->addWidget(g_R, 14, 1, Qt::AlignCenter);
  gl->addWidget(g_F, 14, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 14, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("h"), 15, 0, Qt::AlignRight);
  gl->addWidget(h_R, 15, 1, Qt::AlignCenter);
  gl->addWidget(h_F, 15, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 15, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("l"), 16, 0, Qt::AlignRight);
  gl->addWidget(ls, 16, 1, 1, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("m"), 16, 3, Qt::AlignLeft);

  gl->addWidget(new QLabel("gravity"), 17, 0, Qt::AlignRight);
  gl->addWidget(g, 17, 1, 1, 2, Qt::AlignCenter);
  gl->addWidget(new QLabel("m/s^2"), 17, 3, Qt::AlignLeft);
} // createGridLayout()

void GyrostatParameterForm::setIxx_R(double d)
{
  qDebug() << "GyrostatParameterForm::setIxx_R(double d)";
  bp_.rear.gyrostat.I.xx = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setIyy_R(double d)
{
  bp_.rear.gyrostat.I.yy = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setIzz_R(double d)
{
  bp_.rear.gyrostat.I.zz = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setIxy_R(double d)
{
  bp_.rear.gyrostat.I.xy = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setIyz_R(double d)
{
  bp_.rear.gyrostat.I.yz = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setIxz_R(double d)
{
  bp_.rear.gyrostat.I.xz = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setJ_R(double d)
{
  bp_.rear.gyrostat.J = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setm_R(double d)
{
  bp_.rear.gyrostat.m = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::seta_R(double d)
{
  bp_.rear.a = d;
  emit ConstraintParametersChanged();
}

void GyrostatParameterForm::setb_R(double d)
{
  bp_.rear.b = d;
  emit ConstraintParametersChanged();
}

void GyrostatParameterForm::setd_R(double d)
{
  bp_.rear.gyrostat.d = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::sete_R(double d)
{
  bp_.rear.gyrostat.e = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setf_R(double d)
{
  bp_.rear.gyrostat.f = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setg_R(double d)
{
  bp_.rear.g = d;
  emit ConstraintParametersChanged();
}

void GyrostatParameterForm::seth_R(double d)
{
  bp_.rear.h = d;
  emit ConstraintParametersChanged();
}

void GyrostatParameterForm::setIxx_F(double d)
{
  bp_.front.gyrostat.I.xx = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setIyy_F(double d)
{
  bp_.front.gyrostat.I.yy = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setIzz_F(double d)
{
  bp_.front.gyrostat.I.zz = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setIxy_F(double d)
{
  bp_.front.gyrostat.I.xy = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setIyz_F(double d)
{
  bp_.front.gyrostat.I.yz = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setIxz_F(double d)
{
  bp_.front.gyrostat.I.xz = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setJ_F(double d)
{
  bp_.front.gyrostat.J = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setm_F(double d)
{
  bp_.front.gyrostat.m = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::seta_F(double d)
{
  bp_.front.a = d;
  emit ConstraintParametersChanged();
}

void GyrostatParameterForm::setb_F(double d)
{
  bp_.front.b = d;
  emit ConstraintParametersChanged();
}

void GyrostatParameterForm::setd_F(double d)
{
  bp_.front.gyrostat.d = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::sete_F(double d)
{
  bp_.front.gyrostat.e = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setf_F(double d)
{
  bp_.front.gyrostat.f = d;
  emit ParametersChanged();
}

void GyrostatParameterForm::setg_F(double d)
{
  bp_.front.g = d;
  emit ConstraintParametersChanged();
}

void GyrostatParameterForm::seth_F(double d)
{
  bp_.front.h = d;
  emit ConstraintParametersChanged();
}

void GyrostatParameterForm::setls(double d)
{
  bp_.ls = d;
  emit ConstraintParametersChanged();
}

void GyrostatParameterForm::setg(double d)
{
  bp_.ls = d;
  emit ParametersChanged();
}

QDoubleSpinBox * GyrostatParameterForm::createSpinBox(double value, double min,
                                          double max, double inc)
{
  QDoubleSpinBox * sb = new QDoubleSpinBox;
  sb->setDecimals(4);
  sb->setRange(min, max);
  sb->setSingleStep(inc);
  sb->setValue(value);
  return sb;
} // createSpinBox()
