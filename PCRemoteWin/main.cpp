#include <QtGui/QApplication>
#include "mainwindow.h"
#include "configuration.h"

int main(int argc, char *argv[])
{
    Configuration::load();
    QApplication a(argc, argv);
    QApplication::setQuitOnLastWindowClosed(false);
    MainWindow w;
    w.showTrayIcon();

    return a.exec();
}
