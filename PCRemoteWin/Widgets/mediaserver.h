#ifndef MEDIASERVER_H
#define MEDIASERVER_H

#include <QWidget>
#include <QPluginLoader>
#include <QLibrary>
#include <iostream>
#include <QDir>
#include "Widgets/mediacontroller.h"
#include "export/ServerMediaPlugin.h"
#include <QList>
#include <QVBoxLayout>
#include <QList>

using namespace std;

class MediaServer : public QWidget
{
    Q_OBJECT
    void listPlugins();
    int pluglen;
    QList <MediaController*> mcs;
    QVBoxLayout *layout;
    ServerMediaPlugin ** plugins;
public:
    explicit MediaServer(QWidget *parent = 0);
    virtual ~MediaServer();
    void start();
    void stop();
public slots:
    void playerConnected();
    void playerDisconnected();
};

#endif // MEDIASERVER_H
