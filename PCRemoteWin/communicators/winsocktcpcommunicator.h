#ifndef WINSOCKTCPCOMMUNICATOR_H
#define WINSOCKTCPCOMMUNICATOR_H

#include <winsock2.h>
#include "abstractcommunicator.h"
#include <iostream>
#include <cstdio>
#include <list>

#define PORT 1234
#define MESSAGE_BUFF 20

using namespace std;

class WinsockTcpCommunicator;

//-----------------------------------------------
class Client{
    SOCKET sock;
    HANDLE thHandle;
    WinsockTcpCommunicator *parent;
    friend DWORD WINAPI run(LPVOID lpParam);
    void processMessage(char *buff);
public:
    Client(SOCKET s, WinsockTcpCommunicator *parent)
    {
        this->sock = s;
        this->parent = parent;
    }
    void start();
};
//---------------------------------------------------

class WinsockTcpCommunicator : public AbstractCommunicator
{
    WSADATA wsaData;
    int retval;
    SOCKET listenfd, connfd;
    sockaddr_in  server_addr, client_addr;
    int client_addr_len, server_addr_len;
    time_t rawtime;
    tm* timeinfo;
    list <Client*> clients;
    list <Client*> removeLaterClients;
public:
    WinsockTcpCommunicator();
    ~WinsockTcpCommunicator();
    void Listen();
    void removeLater(Client *c);
};

#endif // WINSOCKTCPCOMMUNICATOR_H
