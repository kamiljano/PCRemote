#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : SlidingWindow(parent)
{
    tray = new Tray(this);
    layout = new QVBoxLayout();
    cv = new ClientsView();
    layout->addWidget(cv,0,Qt::AlignHCenter);
    tray->setClientsView(cv);
    ms = new MediaServer();
    layout->addWidget(ms,0,Qt::AlignHCenter);
    this->setLayout(layout);
    ms->start();
}

MainWindow::~MainWindow()
{
    delete layout;
    delete tray;
    delete cv;
    delete ms;
}

void MainWindow::focusOutEvent ( QFocusEvent * )
{
    //this->hide();
}

void MainWindow::showTrayIcon()
{
    tray->Show();
}
