#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPropertyAnimation>

#include "slidingwindow.h"
#include "tray.h"

class MainWindow : public SlidingWindow
{
    void focusOutEvent ( QFocusEvent * );
    Tray * tray;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showTrayIcon();
};

#endif // MAINWINDOW_H
