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
    public partial class MouseScroll : UserControl
    {

        public delegate void Scroll (orientation o, dir d);
        public event Scroll OnScrolled;

        public MouseScroll()
        {
            InitializeComponent();
            Touch.FrameReported += this.Touch_FrameReported;
        }

        public enum orientation {Horizontal, Vertical};
        public enum dir {Minus, Plus};
        public orientation ScrollOrientation { get; set; }

        double pos;

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
                            if (ScrollOrientation.Equals(orientation.Vertical))
                            {
                                if (tp.Action.Equals(TouchAction.Down))
                                    pos = tp.Position.Y;
                                else if (OnScrolled != null)
                                    OnScrolled(this.ScrollOrientation, tp.Position.Y > pos ? dir.Plus : dir.Minus);
                            }
                            else
                            {
                                if (tp.Action.Equals(TouchAction.Down))
                                    pos = tp.Position.X;
                                else if (OnScrolled != null)
                                    OnScrolled(this.ScrollOrientation, tp.Position.X > pos ? dir.Plus : dir.Minus);
                            }
                        }
                    }
                }
                catch { }
            }
        }
    }
}
