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
        private sbyte state = 3;
        
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

        public KeyboardEventMessage(int keyCode, sbyte status)
        {
            ResolveCode(keyCode);
            if (status >= 1 && status <= 3)
                this.state = status;
        }

        public KeyboardEventMessage(int keyCode)
        {
            ResolveCode(keyCode);
        }

        private void ResolveCode(int keyCode)
        {
            switch (keyCode)
            {
                case 8:
                    this.keyCode = (sbyte)KeyCode.BACKSPACE;
                    break;
                case 0x41:
                    this.keyCode = (sbyte)KeyCode.A;
                    break;
                case 0x42:
                    this.keyCode = (sbyte)KeyCode.B;
                    break;
                case 0x43:
                    this.keyCode = (sbyte)KeyCode.C;
                    break;
                case 0x44:
                    this.keyCode = (sbyte)KeyCode.D;
                    break;
                case 0x45:
                    this.keyCode = (sbyte)KeyCode.E;
                    break;
                case 0x46:
                    this.keyCode = (sbyte)KeyCode.F;
                    break;
                case 0x47:
                    this.keyCode = (sbyte)KeyCode.G;
                    break;
                case 0x48:
                    this.keyCode = (sbyte)KeyCode.H;
                    break;
                case 0x49:
                    this.keyCode = (sbyte)KeyCode.I;
                    break;
                case 0x4A:
                    this.keyCode = (sbyte)KeyCode.J;
                    break;
                case 0x4B:
                    this.keyCode = (sbyte)KeyCode.K;
                    break;
                case 0x4C:
                    this.keyCode = (sbyte)KeyCode.L;
                    break;
                case 0x4D:
                    this.keyCode = (sbyte)KeyCode.M;
                    break;
                case 0x4E:
                    this.keyCode = (sbyte)KeyCode.N;
                    break;
                case 0x4F:
                    this.keyCode = (sbyte)KeyCode.O;
                    break;
                case 0x50:
                    this.keyCode = (sbyte)KeyCode.P;
                    break;
                case 0x51:
                    this.keyCode = (sbyte)KeyCode.Q;
                    break;
                case 0x52:
                    this.keyCode = (sbyte)KeyCode.R;
                    break;
                case 0x53:
                    this.keyCode = (sbyte)KeyCode.S;
                    break;
                case 0x54:
                    this.keyCode = (sbyte)KeyCode.T;
                    break;
                case 0x55:
                    this.keyCode = (sbyte)KeyCode.U;
                    break;
                case 0x56:
                    this.keyCode = (sbyte)KeyCode.V;
                    break;
                case 0x57:
                    this.keyCode = (sbyte)KeyCode.W;
                    break;
                case 0x58:
                    this.keyCode = (sbyte)KeyCode.X;
                    break;
                case 0x59:
                    this.keyCode = (sbyte)KeyCode.Y;
                    break;
                case 0x5A:
                    this.keyCode = (sbyte)KeyCode.Z;
                    break;
                case 0x30:
                    this.keyCode = (sbyte)KeyCode.B0;
                    break;
                case 0x31:
                    this.keyCode = (sbyte)KeyCode.B1;
                    break;
                case 0x32:
                    this.keyCode = (sbyte)KeyCode.B2;
                    break;
                case 0x33:
                    this.keyCode = (sbyte)KeyCode.B3;
                    break;
                case 0x34:
                    this.keyCode = (sbyte)KeyCode.B4;
                    break;
                case 0x35:
                    this.keyCode = (sbyte)KeyCode.B5;
                    break;
                case 0x36:
                    this.keyCode = (sbyte)KeyCode.B6;
                    break;
                case 0x37:
                    this.keyCode = (sbyte)KeyCode.B7;
                    break;
                case 0x38:
                    this.keyCode = (sbyte)KeyCode.B8;
                    break;
                case 0x39:
                    this.keyCode = (sbyte)KeyCode.B9;
                    break;
                case 0x20:
                    this.keyCode = (sbyte)KeyCode.SPACE;
                    break;
            }
        }

        public sbyte[] Message()
        {
            return new sbyte[] { 6, state, keyCode};
        }

        public Protocol NetworkProtocol { get { return Protocol.TCP; } }
    }
}
