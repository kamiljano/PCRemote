using System;
using System.ComponentModel;

namespace PCRemoteWP
{
    public class ServerData : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private string name;
        private string address;
        private int port;

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Name"));
            }
        }
        public string Address
        {
            get
            {
                return address;
            }
            set
            {
                address = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Address"));
            }
        }
        public int Port
        {
            get
            {
                return port;
            }
            set
            {
                port = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Port"));
            }
        }

        public ServerData() { }
        public ServerData(string name, string address, int port)
        {
            this.Name = name;
            this.Address = address;
            this.Port = port;
        }
    }
}
