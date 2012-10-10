#include "serverwinampplugin.h"

ServerWinampPlugin::ServerWinampPlugin() : ServerMediaPlugin()
{
    waiter = new Waiter(this);
    connected = false;
}

ServerWinampPlugin::~ServerWinampPlugin()
{
    waiter->setEnd();
    waiter->wait();
    delete waiter;
}

void ServerWinampPlugin::start()
{
    waiter->setStart();
    cout<<"-- Winamp plugin started"<<endl;
    waiter->start();
}

void ServerWinampPlugin::stop()
{
    waiter->setEnd();
}

void ServerWinampPlugin::pause()
{

}

void ServerWinampPlugin::play()
{

}

void ServerWinampPlugin::next()
{

}

void ServerWinampPlugin::previous()
{

}

void Waiter::run()
{
    while (!end)
    {
        QThread::sleep(1);
        hwnd = FindWindowA("Winamp v1.x",NULL);
        if (hwnd != NULL && !connected)
        {
            connected = true;
            //emit winampDetected();
            parent->winampDetectedSlot();
        }
        else if (hwnd == NULL && connected)
        {
            connected = false;
            //emit winampGone();
            parent->winampGoneSlot();
        }
    }
}
SERVERWINAMPPLUGINSHARED_EXPORT ServerWinampPlugin* getPluginInstance()
{
    //cout<<"Receiving pluign instance"<<endl;
    return new ServerWinampPlugin();
}

QPixmap ServerWinampPlugin::getLogo()
{
    return QPixmap();
}

bool ServerWinampPlugin::isPlaying()
{
    return false;
}

QString ServerWinampPlugin::currentTrack()
{
    return "";
}

bool ServerWinampPlugin::isConnected()
{
    return connected;
}

void ServerWinampPlugin::winampDetectedSlot()
{
    this->connected = true;
    emit playerConnected(this);
}

void ServerWinampPlugin::winampGoneSlot()
{
    this->connected = false;
    playerDisconnected(this);
}
