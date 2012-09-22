#ifndef TCPCOMMUNICATOR_H
#define TCPCOMMUNICATOR_H

#include "abstractcommunicator.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <QObject>
#include <QUdpSocket>
#include "../messagewindow.h"
#include <QHostInfo>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>

#define BUFLEN 300

using namespace std;

//QString getLocalhostInfo();

class TcpCommunicator : public AbstractCommunicator
{
    Q_OBJECT
    QUdpSocket *udpSocket;
    int port;
public:
    explicit TcpCommunicator(QObject *parent = 0);
    QTcpServer *server;
    ~TcpCommunicator();
    void Listen();
    QString getLocalhostInfo();
private slots:
    void addClient();
    void removeClient();
    void process();
    void processUDP();
};

#endif // TCPCOMMUNICATOR_H