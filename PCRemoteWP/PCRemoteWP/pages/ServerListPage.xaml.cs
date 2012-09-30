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

namespace PCRemoteWP
{
    public partial class ServerList : PhoneApplicationPage
    {
        public ServerList()
        {
            InitializeComponent();
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
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
            controls.ServerButton b;
            foreach (ServerData sd in ServersStorage.Servers)
            {
                b = new controls.ServerButton();
                b.ServerData = sd;
                b.Click += delegate(object sender, RoutedEventArgs ee) {
                    ServersStorage.SelectedServer = (sender as controls.ServerButton).ServerData;
                    NavigationService.GoBack();
                };
                stack.Children.Add(b);
            }
        }
    }
}