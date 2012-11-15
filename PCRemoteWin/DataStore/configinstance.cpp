#include "configinstance.h"

ConfigInstance::ConfigInstance()
{
    acceptAndroidClients = true;
    this->acceptWPClients = true;
    this->allowAutodetect = true;
    //this->name = "lol";
    for (int i = 0; i < PASSWDMAX; i++)
        password[i]=0;
    this->port=1234;
    this->requirePassword=false;
}

istream& operator>>(istream& in, ConfigInstance& vec)
{
    char * temp = (char*)&vec;
    for (int i = 0; i < sizeof(ConfigInstance); i++)
        in>>temp[i];
    return in;
}

ostream& operator<<(ostream& out, const ConfigInstance& vec)
{
    char * temp = (char*)&vec;
    for (int i = 0; i < sizeof(ConfigInstance); i++)
        out<<temp[i];
    return out;
}
