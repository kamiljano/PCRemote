using System;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;

namespace PCRemoteWP.messages
{
    public class IntroductionMessage : NetworkMessage
    {
        public sbyte[] Message()
        {
            return new sbyte[] { 5, 2 };
        }

        public Protocol NetworkProtocol { get { return Protocol.TCP; } }

        public static byte[] GetMessage() { return new byte[] { 5, 2 }; }
    }
}
