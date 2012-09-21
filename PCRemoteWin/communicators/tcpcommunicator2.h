#ifndef TCPCOMMUNICATOR_H
#define TCPCOMMUNICATOR_H
#include "abstractcommunicator.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <QObject>

#define BUFLEN 300

using namespace std;

class TCPCommunicator : public AbstractCommunicator, public QObject
{
    Q_OBJECT
    QTcpServer *server;
public:
    TCPCommunicator();
    ~TCPCommunicator();
    void listen();
private slots:
    void addClient();
    void removeClient();
    void process();
};

#endif // TCPCOMMUNICATOR_H
