#include "plugin_winamp.h"


Plugin_winamp::Plugin_winamp() : Server_plugin()
{
    //connect (&waiter, SIGNAL(winampConnected()), this, SIGNAL(playerConnected()));
    //connect (&waiter, SIGNAL(winampDisconnected()), this, SIGNAL(playerDisconnected()));
    waiter = new Waiter(this);
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

QString Plugin_winamp::getTrack()
{
    return "";
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
            //emit winampConnected(NAME);
            emit parent->playerConnected(NAME);
        }
        else if (hwnd == NULL && connected)
        {
            connected = false;
           // emit winampDisconnected(NAME);
            emit parent->playerDisconnected(NAME);
        }
    }
}
Plugin_winamp* getPluginInstance()
{
    return new Plugin_winamp();
}
