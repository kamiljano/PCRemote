#include "plugin_winamp.h"


Plugin_winamp::Plugin_winamp() : ServerMediaPlugin()
{
    waiter = new Waiter(this);
    connected = false;
}

Plugin_winamp::~Plugin_winamp()
{
    waiter->setEnd();
    waiter->wait();
    delete waiter;
}

void Plugin_winamp::start()
{
    waiter->setStart();
    cout<<"-- Winamp plugin started"<<endl;
    waiter->start();
}

void Plugin_winamp::stop()
{
    waiter->setEnd();
}

void Plugin_winamp::pause()
{

}

void Plugin_winamp::play()
{

}

void Plugin_winamp::next()
{

}

void Plugin_winamp::previous()
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
Plugin_winamp* getPluginInstance()
{
    //cout<<"Receiving pluign instance"<<endl;
    return new Plugin_winamp();
}

QPixmap Plugin_winamp::getLogo()
{
    return QPixmap();
}

bool Plugin_winamp::isPlaying()
{
    return false;
}

QString Plugin_winamp::currentTrack()
{
    return "";
}

bool Plugin_winamp::isConnected()
{
    return connected;
}

void Plugin_winamp::winampDetectedSlot()
{
    this->connected = true;
    emit playerConnected(this);
}

void Plugin_winamp::winampGoneSlot()
{
    this->connected = false;
    playerDisconnected(this);
}
