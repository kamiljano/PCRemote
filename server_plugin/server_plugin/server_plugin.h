#ifndef SERVER_PLUGIN_H
#define SERVER_PLUGIN_H

#include <QString>
#include <QObject>
//#include <QPixmap>

class Server_plugin : public QObject {
    Q_OBJECT
public:
    Server_plugin();
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual QString playerName() = 0;
    //virtual QPixmap playerIcon() = 0;
    virtual QString getTrack() = 0;
    virtual void pause() = 0;
    virtual void play() = 0;
    virtual void next() = 0;
    virtual void previous() = 0;
signals:
    void playerConnected(QString);
    void playerDisconnected(QString);
    void trackChanged();
};

#endif // SERVER_PLUGIN_H
