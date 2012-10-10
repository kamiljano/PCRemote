#ifndef SERVERMEDIAPLUGIN_H
#define SERVERMEDIAPLUGIN_H

#include <QPixmap>

class ServerMediaPlugin : public QObject {
    Q_OBJECT
public:
    ServerMediaPlugin(QObject * parent = 0) : QObject(parent){}
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual QString playerName() = 0;
    virtual QPixmap getLogo() = 0;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void next() = 0;
    virtual void previous() = 0;
    virtual bool isPlaying() = 0;
    virtual QString currentTrack() = 0;
    virtual bool isConnected() = 0;
signals:
    void trackPaused();
    void newTrack(QString);
    void playerConnected(ServerMediaPlugin *);
    void playerDisconnected(ServerMediaPlugin *);
};

#endif // SERVERMEDIAPLUGIN_H
