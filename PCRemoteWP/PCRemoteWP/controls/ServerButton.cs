using System;
using System.Windows.Controls;

namespace PCRemoteWP.controls
{
    public class ServerButton : Button
    {
        ServerData sd;
        public ServerData ServerData
        {
            get
            {
                return sd;
            }
            set
            {
                sd = value;
                this.Content = value.Name;
            }
        }
    }
}
