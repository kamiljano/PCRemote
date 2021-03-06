﻿using System;
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
using System.Diagnostics;

namespace PCRemoteWP.pages
{
    public partial class MousePage : PhoneApplicationPage
    {
        public MousePage()
        {
            InitializeComponent();
        }

        private void PhoneApplicationPage_Loaded(object sender, RoutedEventArgs e)
        {
            this.mouseController.startSendingThread();
        }

        protected override void OnNavigatedFrom(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedFrom(e);
            ServersStorage.OnConnectionFailed -= processConnectionFailed;
            this.mouseController.Kill();
        }

        private void processConnectionFailed()
        {
            MessageBox.Show("Connection failed");
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            ServersStorage.OnConnectionFailed += processConnectionFailed;
            ServersStorage.ReestabilishConnection();
        }

    }
}