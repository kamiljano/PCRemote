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
};

#endif // CONFIGURATION_H
