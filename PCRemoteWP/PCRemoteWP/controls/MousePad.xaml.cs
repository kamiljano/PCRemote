using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;

namespace PCRemoteWP.controls
{
    public partial class MousePad : UserControl
    {
        public delegate void MouseMove(byte x, byte y);
        public event MouseMove OnMouseMove;
        private double last_x, last_y;

        public MousePad()
        {
            InitializeComponent();
            Touch.FrameReported += this.Touch_FrameReported;
        }
        private void Touch_FrameReported(object sender, TouchFrameEventArgs e)
        {
            if (e != null)
            {
                try
                {
                    TouchPointCollection col = e.GetTouchPoints(this);
                    if (col != null)
                    {
                        foreach (TouchPoint tp in col)
                        {
                            if (tp.Action.Equals(TouchAction.Down))
                            {
                                this.last_x = tp.Position.X;
                                this.last_y = tp.Position.Y;
                            }
                            else
                            {
                                if (OnMouseMove != null)
                                    OnMouseMove((byte)(tp.Position.X - this.last_x), (byte)(tp.Position.Y - this.last_y));
                            }
                        }
                    }
                }
                catch { }
            }
        }  
    }
}
