﻿using System;
using System.Collections.Generic;
using System.Xml;
using System.Xml.Serialization;
using System.IO;
using System.IO.IsolatedStorage;
using System.Net.Sockets;
using System.Diagnostics;
using System.Threading;
using System.Net;
using System.Windows.Threading;
using System.Windows;
using PCRemoteWP.messages;
using System.Collections.ObjectModel;

namespace PCRemoteWP
{
    public static class ServersStorage
    {
        private const string filename = @"servers.xml";

        private static ObservableCollection<ServerData> ss;

        public static ServerData ForEdit = null;

        public static ObservableCollection<ServerData> Servers
        {
            get
            {
                if (ss == null)
                {
                    try
                    {
                        DeserializeFromXML();
                        //loadAsText();
                    }
                    catch
                    {
                        ss = new ObservableCollection<ServerData>();
                    }
                }
                return ss;
            }
        }

        /// <summary>
        /// Saves all the information about available servers
        /// Might throw exception if serialization fails
        /// </summary>
        public static void Save()
        {
            if (ss != null && ss.Count > 0)
                SerializeToXML();
                //saveAsText();
        }

        private static void saveAsText()
        {
            var ss = Servers;
            IsolatedStorageFile myStore = IsolatedStorageFile.GetUserStoreForApplication();

            
            using (var isoFileStream = new IsolatedStorageFileStream(filename, FileMode.OpenOrCreate, myStore))
            {
                using (StreamWriter writer = new StreamWriter(isoFileStream))
                {
                    foreach (ServerData sd in ss)
                    {
                        string temp = sd.Name + "\r" + sd.Address + "\r" + sd.Port + "\n";
                        writer.WriteLine(temp);
                    }
                }
            }
        }

        private static void loadAsText()
        {
            IsolatedStorageFile myStore = IsolatedStorageFile.GetUserStoreForApplication();
            ObservableCollection<ServerData> servers = new ObservableCollection<ServerData>() ;
            using (var isoFileStream = new IsolatedStorageFileStream(filename, FileMode.Open, myStore))
            {
                using (StreamReader reader = new StreamReader(isoFileStream))
                {
                    string temp = reader.ReadToEnd();
                    MessageBox.Show(temp);
                    /*var arr = temp.Split('\n');
                    foreach (string v in arr)
                    {
                        if (v.Length > 0)
                        {
                            var vals = v.Split('\r');
                            ServerData sd = new ServerData(vals[0], vals[1], int.Parse(vals[2]));
                            servers.Add(sd);
                        }
                    }*/
                }
            }
            ss = servers;
        }

        private static void SerializeToXML()
        {
            var ss = Servers;
            IsolatedStorageFile myStore = IsolatedStorageFile.GetUserStoreForApplication();

            XmlSerializer serializer = new XmlSerializer(typeof(ObservableCollection<ServerData>));
            using (var isoFileStream = new IsolatedStorageFileStream(filename, FileMode.OpenOrCreate, myStore))
            {
                serializer.Serialize(isoFileStream, ss);
            }
        }

        private static void DeserializeFromXML()
        {
            IsolatedStorageFile myStore = IsolatedStorageFile.GetUserStoreForApplication();
            XmlSerializer deserializer = new XmlSerializer(typeof(List<ServerData>));
            List<ServerData> servers;
            using (var isoFileStream = new IsolatedStorageFileStream(filename, FileMode.Open, myStore))
            {
                servers = (List<ServerData>)deserializer.Deserialize(isoFileStream);
            }
            ss = new ObservableCollection<ServerData>(servers);
        }

        public static ServerData SelectedServer { set; get; }
        public static Socket ServerSocket { set; get; }
        public delegate void ConnectionFailed();
        public static event ConnectionFailed OnConnectionFailed;

        public static void ReestabilishConnection()
        {
            if (SelectedServer != null && ServerSocket != null && !ServerSocket.Connected)
            {
                Debug.WriteLine("Reestabilishing connection");
                SocketError result = SocketError.Fault;
                Socket _socket = null;
                ManualResetEvent _clientDone = new ManualResetEvent(false);

                DnsEndPoint hostEntry = new DnsEndPoint(SelectedServer.Address, SelectedServer.Port);

                _socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                SocketAsyncEventArgs socketEventArg = new SocketAsyncEventArgs();
                socketEventArg.RemoteEndPoint = hostEntry;

                socketEventArg.Completed += new EventHandler<SocketAsyncEventArgs>(delegate(object s, SocketAsyncEventArgs e)
                {

                    result = e.SocketError;

                    if (!result.Equals(SocketError.Success) && OnConnectionFailed != null)
                        OnConnectionFailed();
                    _clientDone.Set();
                });

                _clientDone.Reset();

                _socket.ConnectAsync(socketEventArg);

                _clientDone.WaitOne(2000);

                if (_socket != null && _socket.Connected)
                {
                    SocketAsyncEventArgs toBeSent = new SocketAsyncEventArgs();
                    toBeSent.RemoteEndPoint = _socket.RemoteEndPoint;
                    toBeSent.UserToken = null;
                    byte[] payload = IntroductionMessage.GetMessage();
                    toBeSent.SetBuffer(payload, 0, payload.Length);
                    _socket.SendAsync(toBeSent);
                    ServersStorage.ServerSocket = _socket;
                }
            }
        }
    }
}
