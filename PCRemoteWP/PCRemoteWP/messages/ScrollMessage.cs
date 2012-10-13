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
        sbyte secondByte;
        sbyte thirdByte;
        public ScrollMessage(MouseScroll.orientation o, sbyte value)
        {
            secondByte = o == MouseScroll.orientation.Horizontal ? (sbyte)2 : (sbyte)1;
            thirdByte = value;
        }

        public sbyte[] Message()
        {
            return new sbyte[] { 1, secondByte, thirdByte};
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
