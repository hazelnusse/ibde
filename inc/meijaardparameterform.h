#ifndef MEIJAARDPARAMETERFORM_H
#define MEIJAARDPARAMETERFORM_H
#include <QWidget>

class QDoubleValidator;
class QDoubleSpinBox;
class Bike;

class MeijaardParameterForm : public QWidget
{
  Q_OBJECT

  public:
    explicit MeijaardParameterForm(QWidget *parent = 0);

  signals:

  private slots:

  private:
    void createSpinBoxes();
    void createGridLayout();

    QDoubleSpinBox *w, *c, *lambda,
                   *rR, *mR,
                   *IRxx, *IRyy,
                   *xB, *zB,
                   *mB, *IBxx, *IByy, *IBzz, *IBxz,
                   *xH, *zH,
                   *mH, *IHxx, *IHyy, *IHzz, *IHxz,
                   *rF, *mF,
                   *IFxx, *IFyy,
                   *g;

    // Ultimately we'll keep a reference to the Bike instance used in the
    // MainWindow
    // Bike &bike;
};
#endif // MEIJAARDPARAMETERFORM_H
