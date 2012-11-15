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
using PCRemoteWP.messages;

namespace PCRemoteWP.pages
{
    public partial class RemotePage : PhoneApplicationPage
    {
        public RemotePage()
        {
            InitializeComponent();
        }

        protected override void OnNavigatedFrom(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedFrom(e);
            ServersStorage.OnConnectionFailed -= processConnectionFailed;
            this.mouseController.Kill();
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            ServersStorage.OnConnectionFailed += processConnectionFailed;
            ServersStorage.ReestabilishConnection();
            this.mouseController.startSendingThread();
        }

        private void processConnectionFailed()
        {
            MessageBox.Show("Connection failed");
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

        private void ShowKeyboardClicked(object sender, RoutedEventArgs e)
        {
            hiddenText.Focus();
        }

        private void TextBox_KeyDown(object sender, KeyEventArgs e)
        {
            //MessageBox.Show(e.OriginalSource.ToString());
            
            KeyboardEventMessage kem = new KeyboardEventMessage(e.PlatformKeyCode);
            mouseController.AddMessageToSend(kem);
            e.Handled = true;
        }
    }
}