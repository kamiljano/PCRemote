#ifndef NETWORKCOMMUNICATOR_H
#define NETWORKCOMMUNICATOR_H

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
#include <iostream>

#define BUFLEN 300

using namespace std;

class NetworkCommunicator : public AbstractCommunicator
{
    Q_OBJECT
    QUdpSocket *udpSocket;
    int port;
    QTcpServer *server;
public:
    explicit NetworkCommunicator(QObject *parent = 0);
    ~NetworkCommunicator();
    void Listen();
    QString getLocalhostInfo();
private slots:
    void addClient();
    void removeClient();
    void process();
    void processUDP();
};

#endif // NETWORKCOMMUNICATOR_H
