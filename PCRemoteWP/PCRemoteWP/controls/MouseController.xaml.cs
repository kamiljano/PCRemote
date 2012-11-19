using System;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using System.Threading;
using PCRemoteWP.messages;
using System.Net.Sockets;
using System.Diagnostics;
using System.Net;
using PCRemoteWP.storage;

namespace PCRemoteWP.controls
{
    public partial class MouseController : UserControl
    {
        private Thread st;
        private System.Collections.Generic.Queue<NetworkMessage> messageQueue = new System.Collections.Generic.Queue<NetworkMessage>();
        private bool killThread = false;
        private SocketAsyncEventArgs tcptoBeSent = new SocketAsyncEventArgs();
        Socket udpsocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

        public MouseController()
        {
            InitializeComponent();
            this.scrollY.OnScrolled += processScrollEvent;
            this.scrollX.OnScrolled += processScrollEvent;
            this.mousepad.OnMouseMoveEvent += processMouseMoveEvent;
            this.mousepad.OnLeftClick += processLeftClick;
            this.mousepad.OnRightClick += processRightClick;
            this.mousepad.OnLeftDown += processLeftDown;
            this.mousepad.OnLeftUp += processLeftUp;
            tcptoBeSent.RemoteEndPoint = ServersStorage.ServerSocket.RemoteEndPoint;
            tcptoBeSent.UserToken = null;
            st = new Thread(sendingThread);
        }

        public static byte ScrollSensitivity
        {
            get
            {
                return ConfigStorage.Instance.ScrollSensitivity;
            }
            set
            {
                ConfigStorage.Instance.ScrollSensitivity = value;
            }
        }

        public static float MouseSensitivity
        {
            get
            {
                return ConfigStorage.Instance.MouseSensitivity;
            }
            set
            {
                ConfigStorage.Instance.MouseSensitivity = value;
            }
        }

        public static int TimeToRightClick
        {
            get
            {
                return ConfigStorage.Instance.TimeToRightClick;
            }
            set
            {
                ConfigStorage.Instance.TimeToRightClick = value;
            }
        }

        public void AddMessageToSend(NetworkMessage mes)
        {
            lock (messageQueue)
            {
                messageQueue.Enqueue(mes);
            }
        }

        public void processLeftDown()
        {
            Debug.WriteLine("Left mouse down");
            lock (messageQueue)
            {
                messageQueue.Enqueue(new LeftMouseButtonDownMessage());
            }
        }

        public void processLeftUp()
        {
            Debug.WriteLine("Left mouse up");
            lock (messageQueue)
            {
                messageQueue.Enqueue(new LeftMouseButtonUpMessage());
            }
        }

        public void processLeftClick()
        {
            Debug.WriteLine("Left mouse click");
            lock (messageQueue)
            {
                messageQueue.Enqueue(new LeftClickMessage());
            }
        }

        public void processRightClick()
        {
            Debug.WriteLine("Right mouse click");
            lock (messageQueue)
            {
                messageQueue.Enqueue(new RightClickMessage());
            }
        }

        public void processScrollEvent(MouseScroll.orientation o, MouseScroll.dir d)
        {
            Debug.WriteLine("Scroll Scroll: " + (o == MouseScroll.orientation.Horizontal ? "horizontal : " : "vertical : ") +
                (d == MouseScroll.dir.Minus ? "minus" : "plus"));
            lock (messageQueue)
            {
                messageQueue.Enqueue(new ScrollMessage(o, d == MouseScroll.dir.Plus ? (sbyte)MouseController.ScrollSensitivity : (sbyte)(-1 * MouseController.ScrollSensitivity)));
            }
        }

        public void processMouseMoveEvent(sbyte x, sbyte y)
        {
            Debug.WriteLine("Mouse moved; x = " + x + "; y = " + y);
            lock (messageQueue)
            {
                messageQueue.Enqueue(new MouseMoveMessage(x, y));
            }
        }

        public void sendingThread()
        {
            NetworkMessage nm;
            while (!killThread)
            {
                lock (messageQueue)
                {
                    if (messageQueue.Count > 0)
                        nm = messageQueue.Dequeue();
                    else
                        nm = null;
                }
                if (nm != null)
                {
                    if (nm.NetworkProtocol == Protocol.TCP)                 //sending message via TCP
                    {
                        //Debug.WriteLine("Sending event message via TCP");
                        try
                        {
                            sbyte [] message = nm.Message();
                            byte[] payload = new byte[message.Length];
                            for (int i = 0; i < message.Length; i++)
                                payload[i] = (byte)message[i];
                            tcptoBeSent.SetBuffer(payload, 0, payload.Length);
                            ServersStorage.ServerSocket.SendAsync(tcptoBeSent);
                        }
                        catch
                        {
                            Debug.WriteLine("Sending failed");
                            lock (messageQueue)
                            {
                                messageQueue.Clear();
                            }
                        }
                    }
                    else                                            //sending message via UDP
                    {
                        //Debug.WriteLine("Sending event message via UDP");
                        
                        SocketAsyncEventArgs socketEventArg = new SocketAsyncEventArgs();

                        socketEventArg.RemoteEndPoint = new DnsEndPoint(ServersStorage.SelectedServer.Address, ServersStorage.SelectedServer.Port);
                        //ManualResetEvent _clientDone = new ManualResetEvent(false);
                        sbyte[] message = nm.Message();
                        byte[] payload = new byte[message.Length];
                        for (int i = 0; i < message.Length; i++)
                            payload[i] = (byte)message[i];
                        socketEventArg.SetBuffer(payload, 0, payload.Length);
                        //_clientDone.Reset();
                        udpsocket.SendToAsync(socketEventArg);
                    }
                }
            }
        }
        public void Kill()
        {
            killThread = true;
            messageQueue.Clear();
        }
        public void startSendingThread()
        {
            killThread = false;
            st.Start();
        }
    }
}
