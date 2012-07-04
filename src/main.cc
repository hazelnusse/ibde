#include <QApplication>
#include <QStringList>
#include <QDebug>
#include "mainwindow.h"
#include "parameterwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringList arglist = app.arguments();

    MainWindow * w;
    if (arglist.indexOf("--meijaard") != -1)
      w = new MainWindow(ParameterWidget::Meijaard);
    else
      w = new MainWindow(ParameterWidget::Gyrostat);

    w->setWindowTitle(QObject::tr("Interactive Bicycle Dynamics Exploration"));
    w->resize(512, 512);
    w->show();
    int rv = app.exec();
    delete w;
    return rv;
}
