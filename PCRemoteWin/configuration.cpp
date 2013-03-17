#include "configuration.h"

ConfigInstance Configuration::instance;

bool Configuration::acceptAndroidClients()
{
    return instance.acceptAndroidClients;
}

bool Configuration::acceptWPClients()
{
    return instance.acceptWPClients;
}

bool Configuration::requirePassword()
{
    return instance.requirePassword;
}

bool Configuration::allowAutodetect()
{
    return instance.allowAutodetect;
}

QString Configuration::getPassword()
{
    return instance.password;
}

QString Configuration::getComputerName()
{
    return "lol";
}

int Configuration::getDefaultPort()
{
    return instance.port;
}

QString Configuration::getServerName()
{
    return instance.name;
}

int Configuration::getPort()
{
    return instance.port;
}

void Configuration::load()
{
    ifstream in (CONFIGFILE);
    if (in.is_open())
    {
        in>>instance;
        in.close();
    }
}

void Configuration::save()
{
    ofstream out (CONFIGFILE);
    out<<instance;
    out.close();
}

void Configuration::setAcceptAndroidClients(bool value)
{
    instance.acceptAndroidClients = value;
}

void Configuration::setAcceptWPClients(bool value)
{
    instance.acceptWPClients = value;
}

void Configuration::setRequirePassword(bool value)
{
    instance.requirePassword = value;
}

void Configuration::setPassword(QString password)
{
    for (int i = 0; i < PASSWDMAX; i++) {
        instance.password[i] = 0;
    }
    for (int i = 0; i < password.length() && i < 100; i++) {
        instance.password[i] = password[i].toAscii();
    }
}
