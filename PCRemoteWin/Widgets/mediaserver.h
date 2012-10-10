#ifndef MEDIASERVER_H
#define MEDIASERVER_H

#include <QWidget>
#include <QPluginLoader>
#include "server_plugin.h"
#include <QLibrary>
#include <iostream>
#include <QDir>

using namespace std;

class MediaServer : public QWidget
{
    Q_OBJECT
    void listPlugins();
    Server_plugin **plugins;
    int pluglen;
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
