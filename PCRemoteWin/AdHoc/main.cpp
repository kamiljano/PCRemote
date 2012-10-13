#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        //cout<<"ssid="<<argv[1]<<"  password="<<argv[2]<<endl;
        string com = "netsh wlan set hostednetwork mode=allow ssid=";
        com.append(argv[1]);
        com += " key=";
        com.append(argv[2]);
        system(com.c_str());
        system("netsh wlan start hostednetwork");
    }
    else if(argc == 2)
    {
        system("netsh wlan stop hostednetwork");
    }
    //cin.get();
    return 0;
}
