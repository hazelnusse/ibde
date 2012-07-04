#ifndef GYROSTATPARAMETERFORM_H
#define GYROSTATPARAMETERFORM_H
#include <QWidget>
#include "BikeParameters.h"

class QDoubleValidator;
class QDoubleSpinBox;

class GyrostatParameterForm : public QWidget
{
  Q_OBJECT

  public:
    explicit GyrostatParameterForm(BikeParameters<double> & bp, QWidget *parent = 0);

  signals:
    void ConstraintParametersChanged();
    void ParametersChanged();

  private slots:
    void setIxx_R(double d);
    void setIyy_R(double d);
    void setIzz_R(double d);
    void setIxy_R(double d);
    void setIyz_R(double d);
    void setIxz_R(double d);
    void setJ_R(double d);
    void setm_R(double d);
    void seta_R(double d);
    void setb_R(double d);
    void setd_R(double d);
    void sete_R(double d);
    void setf_R(double d);
    void setg_R(double d);
    void seth_R(double d);
    void setIxx_F(double d);
    void setIyy_F(double d);
    void setIzz_F(double d);
    void setIxy_F(double d);
    void setIyz_F(double d);
    void setIxz_F(double d);
    void setJ_F(double d);
    void setm_F(double d);
    void seta_F(double d);
    void setb_F(double d);
    void setd_F(double d);
    void sete_F(double d);
    void setf_F(double d);
    void setg_F(double d);
    void seth_F(double d);
    void setls(double d);
    void setg(double d);

  private:
    void createSpinBoxes();
    void createGridLayout();
    static QDoubleSpinBox * createSpinBox(double value, double min,
                                          double max, double inc);

    BikeParameters<double> & bp_;
    QDoubleSpinBox *Ixx_R, *Ixx_F,
                   *Iyy_R, *Iyy_F,
                   *Izz_R, *Izz_F,
                   *Ixy_R, *Ixy_F,
                   *Iyz_R, *Iyz_F,
                   *Ixz_R, *Ixz_F,
                   *J_R,   *J_F,
                   *m_R,   *m_F,
                   *a_R,   *a_F,
                   *b_R,   *b_F,
                   *d_R,   *d_F,
                   *e_R,   *e_F,
                   *f_R,   *f_F,
                   *g_R,   *g_F,
                   *h_R,   *h_F,
                   *ls, *g;
};
#endif // GYROSTATPARAMETERFORM_H
