#include "messagewindow.h"

MessageWindow::MessageWindow(QWidget *parent) : SlidingWindow(parent)
{
    label = NULL;
    timeout = NULL;
}

MessageWindow::~MessageWindow()
{
    if (label != NULL)
        delete label;
    if (timeout != NULL)
        delete timeout;
}

void MessageWindow::showMessage(QString str)
{
    if (label == NULL)
        label = new QLabel(this);
    initMessage();
    label->setText(str);
    label->move((this->width() - label->width())/2, (this->height() - label->height())/2);
    this->setVisible(true);
    timeout->start();
}

void MessageWindow::initMessage()
{
    if (timeout == NULL)
    {
        timeout = new Timeout(this);
        connect(timeout, SIGNAL(timedOut()), this, SLOT(Hide()));
    }
}

void MessageWindow::showAndroidClientAddedMessage()
{
    if (label == NULL)
        label = new QLabel(this);
    initMessage();
    label->setText("Android client added");
    label->move((this->width() - label->width())/2, (this->height() - label->height())/2);
    this->setVisible(true);
    timeout->start();
}

void MessageWindow::clientDisconnectedMessage()
{
    if (label == NULL)
        label = new QLabel(this);
    initMessage();
    label->setText("Client disconnected");
    label->move((this->width() - label->width())/2, (this->height() - label->height())/2);
    this->setVisible(true);
    timeout->start();
}

void Timeout::run()
{
    QThread::msleep(2000);
    emit timedOut();
}
