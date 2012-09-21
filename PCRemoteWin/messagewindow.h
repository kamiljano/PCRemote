#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QThread>
#include "slidingwindow.h"
#include <iostream>

using namespace std;

class MessageWindow;

class Timeout : public QThread
{
    Q_OBJECT
    MessageWindow *parent;
public:
    Timeout(MessageWindow * parent){this->parent = parent;}
    void run();
signals:
    void timedOut();
};

class MessageWindow : public SlidingWindow
{


    QLabel *label;
    Timeout * timeout;
    void initMessage();

public:
    explicit MessageWindow(QWidget *parent = 0);
    virtual ~MessageWindow();
    void showMessage(QString str);
    void showAndroidClientAddedMessage();
    void clientDisconnectedMessage();
    
};

#endif // MESSAGEWINDOW_H
