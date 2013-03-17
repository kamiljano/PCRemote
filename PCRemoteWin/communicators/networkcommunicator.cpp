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
    short wc;
    QChar * qc;
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
        processIntroduction(arr[1], client);
        break;
    case 6:
        useKeyboard(arr[1], arr[2]);
        break;
    case 7:
        wc = *(arr+1);
        qc = new QChar(wc);
        useKeyboard(*qc);
        delete qc;
        break;
    case 8:
        processDirectoryRequest(arr + 1, client);
        break;
    case 9:
        processDownloadRequest(arr + 1, client);
        break;
    case 10:
        processPasswordValidation(arr + 1, client);
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
        QByteArray pcname = (Configuration::getComputerName() + ";" + QString::number(Configuration::getPort()) ).toUtf8();
        QByteArray message;
        message.append((char)0);
        message.append((char)0);
        message.append(pcname);
        message.append((char)0);
        message.append((char)0);
        udpSocket->writeDatagram(message, sender, 60606);
    }
}

void NetworkCommunicator::processDirectoryRequest(char * path, QTcpSocket * socket) {
    string s(path);
    cout<<"Requested: "<<s<<endl;
    QString response = "";
    QFileInfoList files;
    if (s == "/") {
        files = QDir::drives();
    } else {
        QDir dir(path);
        files = dir.entryInfoList();
    }
    QString len;
    for (QList<QFileInfo>::iterator i = files.begin(); i != files.end(); ++i) {
        response += i->isFile() ? "f" : "d";
        len = QString::number(i->filePath().length());
        while (len.length() < 4) len = "0" + len;
        response += len;
        response += i->filePath();
    }
    len = QString::number(response.length());
    while (len.length() < 15) len = "0" + len;
    response = "01" + len + response;
    cout<<"directory response: "<<endl<<response.toStdString()<<endl;

    socket->write(response.toAscii());
    socket->flush();
}

void NetworkCommunicator::processDownloadRequest(char * path, QTcpSocket * socket) {
    string strPath(path);
    cout<<"Requested file: "<<strPath<<endl;
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray blob = file.readAll();
    QString len = QString::number(blob.length());
    cout<<"File size: "<<blob.length()<<endl;
    while (len.length() < 15) len = "0" + len;
    QString response = "02" + len;
    socket->write(response.toAscii());
    socket->write(blob);
    socket->flush();
}

void NetworkCommunicator::processIntroduction(char type, QTcpSocket * socket){
    QString response;
    if ((type == 1 && Configuration::acceptAndroidClients()) || (type == 2 && Configuration::acceptWPClients())) {
        if (Configuration::requirePassword()) {
            response = "030000000000000012";
            socket->write(response.toAscii());
        } else {
            response = "030000000000000011";
            socket->write(response.toAscii());
            newClientInformation(type);
        }
    } else {
        response = "030000000000000010";
        socket->write(response.toAscii());
        socket->disconnectFromHost();
        cout<<"Client rejected"<<endl;
    }
}

void NetworkCommunicator::processPasswordValidation(char * password, QTcpSocket * socket) {
    string pass(password);
    cout<<"Password received: "<<pass<<endl<<"Actuall password: "<<Configuration::getPassword().toStdString()<<endl;
    char answer[1];
    if (pass == Configuration::getPassword().toStdString()) {
        answer[0] = 1;
        socket->write(answer);
        socket->flush();
    } else {
        answer[0] = 0;
        socket->write(answer);
        socket->flush();
        socket->disconnectFromHost();
    }

}
