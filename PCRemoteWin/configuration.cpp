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
