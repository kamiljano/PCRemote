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
using System.Net.Sockets;
using System.Threading;
using System.Text;

namespace PCRemoteWP.pages
{
    public partial class ServerList : PhoneApplicationPage
    {

        private bool toBeSaved;
        private Thread thread;

        public ServerList()
        {
            InitializeComponent();
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            toBeSaved = false;
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
            
            listbox.ItemsSource = ServersStorage.Servers;
        }

        protected override void OnNavigatedFrom(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedFrom(e);
            if (toBeSaved)
                ServersStorage.Save();
        }
        private void button1_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new Uri("/pages/NewServerPage.xaml?rm=true", UriKind.Relative));
        }

        private void MenuItem_Click_1(object sender, RoutedEventArgs e)
        {
           //ItemViewModel item = (sender as MenuItem).DataContext as ItemViewModel;
            
           // ListBoxItem item = sender as ListBoxItem;
            //MessageBox.Show((sender as MenuItem).DataContext.ToString());
            ServersStorage.Servers.Remove(((sender as MenuItem).DataContext as ServerData));
            listbox.ItemsSource = ServersStorage.Servers;
            //toBeSaved = true;
            ServersStorage.Save();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            //string name = (((sender as Button).Content as Grid).FindName("Name") as TextBlock).Text;
            string address = (((sender as Button).Content as Grid).FindName("Address") as TextBlock).Text;
            string port = (((sender as Button).Content as Grid).FindName("Port") as TextBlock).Text;
            hostName = address;
            portNumber = int.Parse(port);
            if (thread == null || !thread.IsAlive)
            {
                thread = new Thread(Connect);
                thread.Start();
            }
            //MessageBox.Show("test");
        }

        private string hostName;
        private int portNumber;

        private void Connect()
        {
            SocketError result = SocketError.Fault;
            Socket _socket = null;
            ManualResetEvent _clientDone = new ManualResetEvent(false);

            DnsEndPoint hostEntry = new DnsEndPoint(hostName, portNumber);
 
            _socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            SocketAsyncEventArgs socketEventArg = new SocketAsyncEventArgs();
            socketEventArg.RemoteEndPoint = hostEntry;

            socketEventArg.Completed += new EventHandler<SocketAsyncEventArgs>(delegate(object s, SocketAsyncEventArgs e)
            {
                
                result = e.SocketError;
                Console.WriteLine("Connection: " + result.ToString());

                if (!result.Equals(SocketError.Success))
                    Dispatcher.BeginInvoke(delegate() { MessageBox.Show("Failed to connect"); });
                else
                {
                    Dispatcher.BeginInvoke(delegate() { NavigationService.GoBack(); });
                }
                _clientDone.Set();
            });

            _clientDone.Reset();

            _socket.ConnectAsync(socketEventArg);

            _clientDone.WaitOne(5000);

            if (_socket != null && _socket.Connected)
            {
                SocketAsyncEventArgs toBeSent = new SocketAsyncEventArgs();
                toBeSent.RemoteEndPoint = _socket.RemoteEndPoint;
                toBeSent.UserToken = null;
                byte[] payload = new byte[] { 5, 2 };
                toBeSent.SetBuffer(payload, 0, payload.Length);
                _socket.SendAsync(toBeSent);
                ServersStorage.ServerSocket = _socket;
            }
        }
    }
}