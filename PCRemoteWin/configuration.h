#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QString>
#include <iostream>
#include <fstream>
#include "DataStore/configinstance.h"

#define CONFIGFILE "config.dat"

using namespace std;

class Configuration
{
    static ConfigInstance instance;
public:
    static bool acceptAndroidClients();
    static bool acceptWPClients();
    static bool requirePassword();
    static bool allowAutodetect();
    static QString getPassword();
    static QString getComputerName();
    static int getDefaultPort();
    static int getPort();
    static QString getServerName();
    static void save();
    static void load();

    static void setAcceptAndroidClients(bool value);
    static void setAcceptWPClients(bool value);
    static void setRequirePassword(bool value);
};

#endif // CONFIGURATION_H
