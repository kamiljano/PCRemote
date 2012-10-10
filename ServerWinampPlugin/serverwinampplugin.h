#ifndef SERVERWINAMPPLUGIN_H
#define SERVERWINAMPPLUGIN_H

#include "ServerWinampPlugin_global.h"
#include <QString>
#include "ServerMediaPlugin.h"
#include <Windows.h>
#include <QThread>
#include <iostream>
using namespace std;

#define NAME "Winamp"

class SERVERWINAMPPLUGINSHARED_EXPORT ServerWinampPlugin;

class SERVERWINAMPPLUGINSHARED_EXPORT Waiter : public QThread
{
    HWND hwnd;
    bool end;
    bool connected;
    ServerWinampPlugin * parent;
public:
    Waiter(ServerWinampPlugin * parent) {end = false; connected = false; this->parent = parent;}
    void run();
    HWND getHandler() {return hwnd; }
    void setEnd() { end = true; }
    void setStart() {end = false; }
};

class SERVERWINAMPPLUGINSHARED_EXPORT ServerWinampPlugin : public ServerMediaPlugin{
    Q_OBJECT
    HWND hwnd;
    Waiter *waiter;
    bool connected;
public:
    ServerWinampPlugin();
    void start();
    void stop();
    ~ServerWinampPlugin();
    QString playerName(){return NAME;}
    void pause();
    void play();
    void next();
    void previous();
    QPixmap getLogo();
    bool isPlaying();
    QString currentTrack();
    bool isConnected();
public slots:
    void winampDetectedSlot();
    void winampGoneSlot();
};

#endif // SERVERWINAMPPLUGIN_H
