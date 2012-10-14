using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using Microsoft.Phone.Controls;

namespace PCRemoteWP.pages
{
    public partial class NewServerPage : PhoneApplicationPage
    {
        public NewServerPage()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, RoutedEventArgs re)
        {
            bool e = false;
            string emsg = "";
            if (tName.Text.Length == 0)
            {
                e = true;
                emsg = "- Name for the server\n";
            }
            if (tAddress.Text.Length == 0)
            {
                e = true;
                emsg += "- Address of the server\n";
            }
            if (tPort.Text.Length == 0)
            {
                e = true;
                emsg += "- Port of the server";
            }
            if (e)
            {
                MessageBox.Show("In order to proceed, you have to fill the following fields first:\n" + emsg);
                return;
            }
            ServersStorage.Servers.Add(new ServerData(tName.Text, tAddress.Text, int.Parse(tPort.Text)));
            try
            {
                ServersStorage.Save();
            }
            catch
            {
                MessageBox.Show("Failed to save server information");
                return;
            }
            string msg;
            try
            {
                if (NavigationContext.QueryString.TryGetValue("rm", out msg))
                {
                    if (msg.ToLower().Equals("true"))
                        NavigationService.RemoveBackEntry();
                }
            }
            catch { }
            NavigationService.Navigate(new Uri("/pages/ServerListPage.xaml?rm=true", UriKind.Relative));
        }
    }
}