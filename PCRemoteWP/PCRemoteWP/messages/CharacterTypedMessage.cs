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
    public class CharacterTypedMessage : NetworkMessage
    {
        char character;

        public CharacterTypedMessage(char character)
        {
            this.character = character;
        }

        public sbyte[] Message()
        {
            byte[] arr = BitConverter.GetBytes(character);
            return new sbyte[] { 7, (sbyte)arr[0], (sbyte)arr[1]};
        }

        public Protocol NetworkProtocol { get { return Protocol.TCP; } }
    }
}
