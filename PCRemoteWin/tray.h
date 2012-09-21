#ifndef TRAY_H
#define TRAY_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QMenu>
#include <QApplication>
#include <QDesktopWidget>
#include <QCursor>
#include <iostream>
#include "communicators/tcpcommunicator.h"

using namespace std;

class Tray : public QObject
{
    Q_OBJECT
private:
    QSystemTrayIcon *icon;
    QMenu * trayMenu;
    QRect ScreenSize;
    AbstractCommunicator * communicator;
public:

    Tray(QWidget * parent);
    virtual ~Tray();
    virtual void Show();
    virtual void Hide();

public slots:
    void activate(QSystemTrayIcon::ActivationReason reason);
    void exitClicked();
    void optionsClicked();
    void getInfoClicked();
};

#endif // TRAY_H
