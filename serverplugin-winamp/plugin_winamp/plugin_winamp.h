#ifndef PLUGIN_WINAMP_H
#define PLUGIN_WINAMP_H

#include "plugin_winamp_global.h"
#include <QString>
#include "ServerMediaPlugin.h"
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
};

class PLUGIN_WINAMPSHARED_EXPORT Plugin_winamp : public ServerMediaPlugin {
    Q_OBJECT
    HWND hwnd;
    Waiter *waiter;
    bool connected;
public:
    Plugin_winamp();
    void start();
    void stop();
    ~Plugin_winamp();
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

extern "C" PLUGIN_WINAMPSHARED_EXPORT Plugin_winamp* getPluginInstance();


#endif // PLUGIN_WINAMP_H
