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
    public class KeyboardEventMessage : NetworkMessage
    {
        private sbyte keyCode;
        
        public enum KeyCode{
            LSHIFT = 1, RSHIFT, LALT, RALT, SPACE, RCTRL, LCTRL, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R,
            S, T, U, V, W, X, Y, Z, COMA, DOT, SLASH, SEMICOLON, QUOTATION, SQUAREBRACKET1, SQUAREBRACKET2,
            BACKSLASH, TILDA, B1, B2, B3, B4, B5, B6, B7, B8, B9, B0, MINUS, EQUALS, BACKSPACE, ENTER, TAB, CAPSLOCK,
            VOLUP, VOLDOWN, MEDIAPREV, MEDIANEXT, MEDIAPLAY
        }

        public KeyboardEventMessage(KeyCode kc)
        {
            keyCode = (sbyte)kc;
        }

        public sbyte[] Message()
        {
            return new sbyte[] { 6, 3, keyCode};
        }

        public Protocol NetworkProtocol { get { return Protocol.TCP; } }
    }
}
