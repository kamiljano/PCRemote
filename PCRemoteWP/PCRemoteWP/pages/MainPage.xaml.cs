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
    public partial class MainPage : PhoneApplicationPage
    {
        private bool first = true;
        // Constructor
        public MainPage()
        {
            InitializeComponent();
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            if (first)
            {
                goToServers();
                first = false;
            }
        }

        private void goToServers()
        {
            if (ServersStorage.Servers.Count == 0)
                NavigationService.Navigate(new Uri("/pages/NewServerPage.xaml", UriKind.Relative));
            else
                NavigationService.Navigate(new Uri("/pages/ServerListPage.xaml", UriKind.Relative));
        }

        private void bserver_Click(object sender, RoutedEventArgs e)
        {
            goToServers();
        }

        private void bremote_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new Uri("/pages/MousePage.xaml", UriKind.Relative));
        }

        private void bhelp_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new Uri("/pages/AboutPage.xaml", UriKind.Relative));
        }
    }
}