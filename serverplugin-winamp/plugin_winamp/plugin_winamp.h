#ifndef PLUGIN_WINAMP_H
#define PLUGIN_WINAMP_H

#include "plugin_winamp_global.h"
#include <QString>
#include "server_plugin.h"
#include <Windows.h>
#include <QThread>
#include <iostream>
using namespace std;
#define NAME "Winamp"

class PLUGIN_WINAMPSHARED_EXPORT Plugin_winamp;

class PLUGIN_WINAMPSHARED_EXPORT Waiter : public QThread
{
    Q_OBJECT
    HWND hwnd;
    bool end;
    bool connected;
    Plugin_winamp * parent;
public:
    Waiter(Plugin_winamp * parent) {end = false; connected = false; this->parent = parent;}
    void run();
    HWND getHandler() {return hwnd; }
    void setEnd() { end = true; }
    void setStart() {end = false; }
signals:
    void winampConnected(QString);
    void winampDisconnected(QString);
};

class PLUGIN_WINAMPSHARED_EXPORT Plugin_winamp : public Server_plugin {
    HWND hwnd;
    Waiter *waiter;
public:
    Plugin_winamp();
    virtual void start();
    virtual void stop();
    ~Plugin_winamp();
    virtual QString playerName(){return NAME;}
    virtual QString getTrack();
    virtual void pause();
    virtual void play();
    virtual void next();
    virtual void previous();
};

extern "C" PLUGIN_WINAMPSHARED_EXPORT Plugin_winamp* getPluginInstance();


#endif // PLUGIN_WINAMP_H
