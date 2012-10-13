using System;
using System.Collections.Generic;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using Microsoft.Phone.Controls;
using PCRemoteWP.messages;
using System.Net.Sockets;

namespace PCRemoteWP.pages
{
    public partial class MediaControllerPage : PhoneApplicationPage
    {
        public MediaControllerPage()
        {
            InitializeComponent();
        }

        private SocketAsyncEventArgs tcptoBeSent = new SocketAsyncEventArgs();

        private void Send(KeyboardEventMessage kem)
        {
            if (ServersStorage.ServerSocket != null)
            {
                sbyte[] message = kem.Message();
                byte[] payload = new byte[message.Length];
                for (int i = 0; i < message.Length; i++)
                    payload[i] = (byte)message[i];
                tcptoBeSent.SetBuffer(payload, 0, payload.Length);
                ServersStorage.ServerSocket.SendAsync(tcptoBeSent);
            }
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

        protected override void OnNavigatedFrom(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedFrom(e);
            ServersStorage.OnConnectionFailed -= processConnectionFailed;
        }

        private void bpaly_Click(object sender, RoutedEventArgs e)
        {
            Send(new KeyboardEventMessage(KeyboardEventMessage.KeyCode.MEDIAPLAY));
        }

        private void bnext_Click(object sender, RoutedEventArgs e)
        {
            Send(new KeyboardEventMessage(KeyboardEventMessage.KeyCode.MEDIANEXT));
        }

        private void bprev_Click(object sender, RoutedEventArgs e)
        {
            Send(new KeyboardEventMessage(KeyboardEventMessage.KeyCode.MEDIAPREV));
        }

        private void bminus_Click(object sender, RoutedEventArgs e)
        {
            Send(new KeyboardEventMessage(KeyboardEventMessage.KeyCode.VOLDOWN));
        }

        private void bplus_Click(object sender, RoutedEventArgs e)
        {
            Send(new KeyboardEventMessage(KeyboardEventMessage.KeyCode.VOLUP));
        }
    }
}