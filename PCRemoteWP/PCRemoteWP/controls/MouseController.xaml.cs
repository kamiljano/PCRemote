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

namespace PCRemoteWP.controls
{
    public partial class MouseController : UserControl
    {
        private Thread st;
        private System.Collections.Generic.Queue<NetworkMessage> messageQueue = new System.Collections.Generic.Queue<NetworkMessage>();
        private bool killThread = false;


        public MouseController()
        {
            InitializeComponent();
            this.scrollY.OnScrolled += processScrollEvent;
            this.scrollX.OnScrolled += processScrollEvent;
            this.mousepad.OnMouseMove += processMouseMoveEvent;
            st = new Thread(sendingThread);
        }

        static MouseController()
        {
            MouseController.ScorllSensitivity = 10;
        }

        public static byte ScorllSensitivity { get; set; }

        public void processScrollEvent(MouseScroll.orientation o, MouseScroll.dir d)
        {
            Debug.WriteLine("Scroll Scroll: " + (o == MouseScroll.orientation.Horizontal ? "horizontal : " : "vertical : ") +
                (d == MouseScroll.dir.Minus ? "minus" : "plus"));
            lock (messageQueue)
            {
                messageQueue.Enqueue(new ScrollMessage(o, d == MouseScroll.dir.Plus ? MouseController.ScorllSensitivity : (byte)(-1 * MouseController.ScorllSensitivity)));
            }
        }

        public void processMouseMoveEvent(byte x, byte y)
        {

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
                    Debug.WriteLine("Sending event message");
                    try
                    {
                        SocketAsyncEventArgs toBeSent = new SocketAsyncEventArgs();
                        toBeSent.RemoteEndPoint = ServersStorage.ServerSocket.RemoteEndPoint;
                        toBeSent.UserToken = null;
                        byte[] payload = nm.Message();
                        toBeSent.SetBuffer(payload, 0, payload.Length);
                        ServersStorage.ServerSocket.SendAsync(toBeSent);
                    }
                    catch {
                        Debug.WriteLine("Sending failed");
                        lock (messageQueue)
                        {
                            messageQueue.Clear();
                        }
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
