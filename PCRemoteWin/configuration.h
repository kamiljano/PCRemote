#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QString>s

class Configuration
{
public:
    Configuration();
    static bool acceptAndroidClients();
    static bool acceptWPClients();
    static bool requirePassword();
    static bool allowAutodetect();
    static QString getPassword();
    static QString getComputerName();
    static int getDefaultPort();
    static int getPort();
    static QString getServerName();
};

#endif // CONFIGURATION_H
