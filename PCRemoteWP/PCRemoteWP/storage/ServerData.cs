using System;

namespace PCRemoteWP
{
    public class ServerData
    {
        public string Name { get; set; }
        public string Address { get; set; }
        public int Port { get; set; }

        public ServerData() { }
        public ServerData(string name, string address, int port)
        {
            this.Name = name;
            this.Address = address;
            this.Port = port;
        }
    }
}
