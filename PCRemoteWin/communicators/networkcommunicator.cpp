#include "networkcommunicator.h"

NetworkCommunicator::NetworkCommunicator(QObject * parent) : AbstractCommunicator()
{
    port = 1234;
    server = new QTcpServer;
    udpSocket = new QUdpSocket;
    connect(server, SIGNAL(newConnection()), this, SLOT(addClient()));
}

NetworkCommunicator::~NetworkCommunicator()
{
    delete server;
    delete udpSocket;
}

void NetworkCommunicator::Listen()
{
    if (!server->listen(QHostAddress::Any, port)){}
       // throw std::exception("Failed to listen");
    if (!udpSocket->bind(port, QUdpSocket::ShareAddress)){}
       // throw std::exception("Failed to bind");
    connect(udpSocket,SIGNAL(readyRead()), this, SLOT(processUDP()));
    cout<<"Listening started"<<endl;

}

QString NetworkCommunicator::getLocalhostInfo()
{
    cout<<"Host name: "<<QHostInfo::localHostName().toStdString()<<endl;
    QString ret = "Host name: " + QHostInfo::localHostName() + '\n';
    QHostInfo info = QHostInfo::fromName( QHostInfo::localHostName() );
    QList <QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    int i;
    for ( i = 0; i< interfaces.count(); i++)
        if (interfaces[i].humanReadableName().contains("wireless", Qt::CaseInsensitive))
            break;
    if (i == interfaces.count())
    {
        ret += "Addresses:\n";
        QHostInfo info = QHostInfo::fromName( QHostInfo::localHostName() );
        QList<QHostAddress> l= info.addresses();
        for(int i=0; i<l.count(); i++) {
            qDebug()<<l[i].toString();
            ret += l[i].toString()+'\n';
        }
    }
    else
    {
        ret += "Address: ";
        QList<QNetworkAddressEntry> addrs = interfaces[i].addressEntries();
        for (i=0; i<addrs.count(); i++)
        {
            if (addrs[i].ip().toString().contains('.'))
            {
                cout<<addrs[i].ip().toString().toStdString()<<endl;
                ret += addrs[i].ip().toString() +'\n';
            }
        }
    }
    ret += "Port: " + QString::number(port);
    cout<< "Port: " << QString::number(port).toStdString()<< endl;
    return ret;
}

void NetworkCommunicator::addClient()
{
    cout<<"Client connected"<<endl;
    QTcpSocket *s = server->nextPendingConnection();
    connect(s,SIGNAL(disconnected()), this, SLOT(removeClient()));
    connect(s, SIGNAL(disconnected()), s, SLOT(deleteLater()));
    connect(s, SIGNAL(readyRead()), this, SLOT(process()));
}

void NetworkCommunicator::removeClient()
{
    QTcpSocket *s= qobject_cast<QTcpSocket*>(sender());
    cout<<"Client disconnected"<<endl;
    message.clientDisconnectedMessage();
    removeNoClient();
}

void NetworkCommunicator::process()
{
    QTcpSocket *client = (QTcpSocket*) sender();
    char arr [BUFLEN];
    for (int i = 0; i<BUFLEN; i++)
        arr[i] = 0;
    client->read(arr,500);
    switch(arr[0])
    {
    case 1:
        scroll(arr[1], arr[2]);
        //cout<<"Scroll: "<<(int)arr[1]<<"    "<<(int)arr[2]<<endl;
        break;
    case 2:
        switch (arr[1])
        {
        case 1: //click
            switch (arr[2])
            {
            case 1:
                leftMouseButton();
                break;
            case 2:
                rightMouseButton();
                break;
            }
            break;
        case 2: //button down
            switch (arr[2])
            {
            case 1:
                leftMouseButtonDown();
                break;
            }
            break;
        case 3: //button down
            switch (arr[2])
            {
            case 1:
                leftMouseButtonUp();
                break;
            }

            break;
        }
        break;
    case 3:
        leftMouseButton();
        break;
    case 4:
        rightMouseButton();
        break;
    case 5:
        newClientInformation(arr[1]);
        break;
    case 6:
        useKeyboard(arr[1], arr[2]);
        break;
    default:
        cout<<"unknown command: "<<(int)arr[0]<<endl;
    }
}

void NetworkCommunicator::processUDP()
{
    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        QHostAddress sender;
        quint16 senderPort;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        //cout<<"mouse move: "<<(int)datagram.at(0)<<" "<<(int)datagram.at(1)<<" "<<(int)datagram.at(2)<<endl;
        switch(datagram.at(0))
        {
        case 0:
            if (datagram.length() == 2)
                scan(datagram,sender, senderPort);
            break;
        case 1:
            moveMouse(datagram.at(1), datagram.at(2));
            break;
        default:
            cout<<"Unknown protocol over UDP"<<endl;
        }
   }
}

void NetworkCommunicator::scan(QByteArray &datagram,QHostAddress &sender,quint16 senderPort)
{
    if (AbstractCommunicator::scan(datagram.at(1)))
    {
        QByteArray pcname = Configuration::getComputerName().toUtf8();
        QByteArray message;
        message.append((char)0);
        message.append((char)0);
        message.append(pcname);
        message.append((char)0);
        message.append((char)0);
        udpSocket->writeDatagram(message, sender, senderPort);
    }
}
