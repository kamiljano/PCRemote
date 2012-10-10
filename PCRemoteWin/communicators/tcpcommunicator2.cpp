#include "tcpcommunicator.h"

TCPCommunicator::TCPCommunicator() : QObject()
{
    server = new QTcpServer;
    connect(server, SIGNAL(newConnection()), this, SLOT(addClient()));
}

TCPCommunicator::~TCPCommunicator()
{
    delete server;
}

void TCPCommunicator::listen()
{
    if (!server->listen(QHostAddress::Any, 1234))
        throw std::exception("failed to listen");
    cout<<"Listening started"<<endl;
}

void TCPCommunicator::addClient()
{
    cout<<"Client connected"<<endl;
    /*Client * client = new Client((QWidget*)parent());
    connect(client->info.socket,SIGNAL(disconnected()), this, SLOT(removeClient()));
    connect(client->info.socket, SIGNAL(disconnected()), client->info.socket, SLOT(deleteLater()));
    connect(client->info.socket, SIGNAL(readyRead()), this, SLOT(process()));*/
}

void TCPCommunicator::removeClient()
{
    QTcpSocket *s= qobject_cast<QTcpSocket*>(sender());
    cout<<"Client disconnected"<<endl;
}

void TCPCommunicator::process()
{
    QTcpSocket *client = (QTcpSocket*) sender();
    char arr [BUFLEN];
    for (int i = 0; i<BUFLEN; i++)
        arr[i] = 0;
    client->read(arr,500);
    cout<<"Received message: "<<arr<<endl;
}
