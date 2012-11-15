#ifndef CONFIGINSTANCE_H
#define CONFIGINSTANCE_H

#include <iostream>
#include <QString>

#define PASSWDMAX 100

using namespace std;

struct ConfigInstance
{
    ConfigInstance();
    friend istream& operator>>(istream& in, ConfigInstance& vec);
    friend ostream& operator<<(ostream& out, const ConfigInstance& vec);
    bool acceptAndroidClients;
    bool acceptWPClients;
    bool requirePassword;
    bool allowAutodetect;
    char password [PASSWDMAX];
    int port;
    char name [100];
};

#endif // CONFIGINSTANCE_H
