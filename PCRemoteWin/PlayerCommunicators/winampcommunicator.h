#ifndef WINAMPCOMMUNICATOR_H
#define WINAMPCOMMUNICATOR_H

#include "export/ServerMediaPlugin.h"
#include <Windows.h>
#include <QPixmap>

#define NAME "Winamp"

class WinampCommunicator : public ServerMediaPlugin
{
    Q_OBJECT
public:
    explicit WinampCommunicator(QObject *parent = 0);
    void start(){}
    void stop(){}
    ~WinampCommunicator(){}
    QString playerName(){return NAME;}
    void pause(){}
    void play(){}
    void next(){}
    void previous(){}
    QPixmap getLogo(){return QPixmap();}
    bool isPlaying(){return false;}
    QString currentTrack(){return "";}
    bool isConnected(){return false;}
signals:
    
public slots:
    
};

#endif // WINAMPCOMMUNICATOR_H
