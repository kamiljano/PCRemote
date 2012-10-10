#include "mediaserver.h"

MediaServer::MediaServer(QWidget *parent) :
    QWidget(parent)
{
    layout = new QVBoxLayout;
    MediaController *mc = new MediaController();
    layout->addWidget(mc);
    mcs.push_back(mc);
    this->setLayout(layout);

    plugins = NULL;
    listPlugins();
}

void MediaServer::listPlugins()
{
    QDir dir(QDir::currentPath() + "/MediaPlugins");
    if (!dir.exists())
    {
        cout<<"Directory doesn't exist: "<<dir.path().toStdString()<<endl;
        dir.mkdir("MediaPlugins");
    }
    else
    {
        QStringList filters;
        filters <<"*.dll";
        QStringList list = dir.entryList(filters, QDir::Files);
        QListIterator<QString> i(list);
        typedef ServerMediaPlugin* (*getInstanceFunction)();
        pluglen = list.size();
        plugins = new ServerMediaPlugin * [pluglen];
        for (int ii = 0; ii<pluglen; ii++)
        {
            plugins [ii] = 0;
        }
        int ii = 0;
        while (i.hasNext())
        {
            QString name = i.next();
            cout<<"Loading: "<<name.toStdString()<<endl;
            QLibrary lib(name);
            getInstanceFunction func = (getInstanceFunction)lib.resolve("getPluginInstance");
            if (func)
            {
                plugins[ii] = func();
                cout<<"Resolved "<<plugins[ii]->playerName().toStdString()<<" plugin"<<endl;
            }
            else
                cout<<"Failed to resolve "<<name.toStdString()<<endl;
            ii++;
        }
    }
}

MediaServer::~MediaServer()
{
    if (plugins != NULL)
    {
        for(int i = 0; i<pluglen; i++)
            if (plugins[i]!=0)
                delete plugins[i];
        delete [] plugins;
    }
    delete layout;
    for (int i = 0; i<mcs.count(); i++)
        delete mcs[i];
    mcs.clear();
}

void MediaServer::start()
{
    for (int i = 0; i < pluglen; i++)
        if (plugins[i] != NULL)
            plugins[i]->start();
}

void MediaServer::stop()
{
    for (int i = 0; i < pluglen; i++)
        if (plugins[i] != NULL)
            plugins[i]->stop();
}

void MediaServer::playerConnected()
{
    cout<<"Player connected"<<endl;
}

void MediaServer::playerDisconnected()
{
    cout<<"Player disconnected"<<endl;
}
