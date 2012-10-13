#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPropertyAnimation>

#include "slidingwindow.h"
#include "tray.h"
#include "Widgets/clientsview.h"
#include "Widgets/mediaserver.h"
#include "QVBoxLayout"

class MainWindow : public SlidingWindow
{
    Tray * tray;
    MediaServer *ms;
    QVBoxLayout *layout;
    ClientsView *cv;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showTrayIcon();
protected:
    void focusOutEvent ( QFocusEvent * );
};

#endif // MAINWINDOW_H
