using System;
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

namespace PCRemoteWP
{
    public class ServersStorage
    {
        private const string filename = @"servers.xml";

        private static List<ServerData> ss;

        public static List<ServerData> Servers {
            get
            {
                if (ss == null)
                {
                    try
                    {
                        DeserializeFromXML();
                    }
                    catch
                    {
                        ss = new List<ServerData>();
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
        }

        private static void SerializeToXML()
        {
            IsolatedStorageFile myStore = IsolatedStorageFile.GetUserStoreForApplication();

            XmlSerializer serializer = new XmlSerializer(typeof(List<ServerData>));
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
            ss = servers;
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
