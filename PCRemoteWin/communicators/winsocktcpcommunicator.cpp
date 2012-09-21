#include "winsocktcpcommunicator.h"

WinsockTcpCommunicator::WinsockTcpCommunicator() : AbstractCommunicator()
{
    retval = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (retval != 0) {
        fprintf(stderr, "WSAStartup failed: %d\n", retval);
        return;
    }

    listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if (listenfd == INVALID_SOCKET) {
        fprintf(stderr, "socket() failed: %d\n", WSAGetLastError());
        return;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family      =   AF_INET;
    server_addr.sin_addr.s_addr =   htonl(INADDR_ANY);
    server_addr.sin_port        =   htons(PORT);
    server_addr_len             =   sizeof(server_addr);
    if (bind(listenfd, (struct sockaddr*) &server_addr, server_addr_len) == SOCKET_ERROR) {
        fprintf(stderr, "bind() failed: %d\n", WSAGetLastError());
        return;
    }
}

WinsockTcpCommunicator::~WinsockTcpCommunicator()
{
    if (closesocket(listenfd) == SOCKET_ERROR) {
        fprintf(stderr, "closesocket() failed: %d\n", WSAGetLastError());
    }

    if (WSACleanup() == SOCKET_ERROR) {
        fprintf(stderr, "WSACleanup failed: %d\n", WSAGetLastError());
    }
}

void WinsockTcpCommunicator::Listen()
{
    if (listen(listenfd, SOMAXCONN) == SOCKET_ERROR) {
        fprintf(stderr, "listen() failed: %d\n", WSAGetLastError());
        return;
    }
    fprintf(stdout, "Server is listening for incoming connection...\n");
    client_addr_len = sizeof(client_addr);
    while (true)
    {
        connfd = accept(listenfd, (struct sockaddr*)&client_addr, &client_addr_len);
        Client * c = new Client(connfd, this);
        c->start();
        clients.push_back(c);
    }
}

void Client::start()
{
    thHandle = CreateThread(NULL, 0, run,this,0,NULL);
    if (thHandle == NULL)
    {
        cerr<<"Failed to create new client thread"<<endl;
    }
}

DWORD WINAPI run(LPVOID lpParam)
{
    Client *c = (Client*)lpParam;
    char buff[MESSAGE_BUFF];
    while (recv(c->sock, buff, sizeof(buff), 0) > 0)
    {
        cout<<"Message received"<<endl;
        c->processMessage(buff);
    }
    if (c->sock != NULL)
         closesocket(c->sock);
    c->parent->removeLater(c);
    return NULL;
}

void Client::processMessage(char *buff)
{

}

void WinsockTcpCommunicator::removeLater(Client * c)
{
    cout<<"Client set for removal"<<endl;
    clients.remove(c);
    removeLaterClients.push_back(c);
}
