#include "configuration.h"

Configuration::Configuration()
{
}

bool Configuration::acceptAndroidClients()
{
    return true;
}

bool Configuration::acceptWPClients()
{
    return true;
}

bool Configuration::requirePassword()
{
    return false;
}

bool Configuration::allowAutodetect()
{
    return true;
}

QString Configuration::getPassword()
{
    return "";
}

QString Configuration::getComputerName()
{

    return "lol";
}

int Configuration::getDefaultPort()
{
    return 1234;
}

QString Configuration::getServerName()
{
    return getComputerName();
}

int Configuration::getPort()
{
    return getDefaultPort();
}
