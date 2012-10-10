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
using PCRemoteWP.controls;

namespace PCRemoteWP.messages
{
    public class ScrollMessage : NetworkMessage
    {
        byte secondByte;
        byte thirdByte;
        public ScrollMessage(MouseScroll.orientation o, byte value)
        {
            secondByte = o == MouseScroll.orientation.Horizontal ? (byte)2 : (byte)1;
            thirdByte = value;
        }

        public byte[] Message()
        {
            return new byte[] { 1, secondByte, thirdByte};
        }

        public Protocol NetworkProtocol
        {
            get
            {
                return Protocol.TCP;
            }
        }
    }
}
