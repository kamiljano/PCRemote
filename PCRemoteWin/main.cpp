#include <QtGui/QApplication>
#include "mainwindow.h"
#include <Windows.h>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showTrayIcon();

    return a.exec();
}
