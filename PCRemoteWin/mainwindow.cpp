#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : SlidingWindow(parent)
{
    tray = new Tray(this);
}

MainWindow::~MainWindow()
{
    delete tray;
}

void MainWindow::focusOutEvent ( QFocusEvent * )
{
    //this->hide();
}

void MainWindow::showTrayIcon()
{
    tray->Show();
}
