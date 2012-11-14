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
            if (ServersStorage.ForEdit == null)
                ServersStorage.Servers.Add(new ServerData(tName.Text, tAddress.Text, int.Parse(tPort.Text)));
            else
            {
                ServersStorage.ForEdit.Name = tName.Text;
                ServersStorage.ForEdit.Address = tAddress.Text;
                ServersStorage.ForEdit.Port = int.Parse(tPort.Text);
            }
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

        protected override void OnNavigatedFrom(System.Windows.Navigation.NavigationEventArgs e)
        {
            ServersStorage.ForEdit = null;
            base.OnNavigatedFrom(e);
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            if (ServersStorage.ForEdit != null)
            {
                tName.Text = ServersStorage.ForEdit.Name;
                tAddress.Text = ServersStorage.ForEdit.Address;
                tPort.Text = ServersStorage.ForEdit.Port.ToString();
            }
        }
    }
}