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
using System.Diagnostics;

namespace PCRemoteWP.controls
{
    public partial class MouseScroll : UserControl
    {

        public delegate void Scroll (orientation o, dir d);
        public event Scroll OnScrolled;

        public MouseScroll()
        {
            InitializeComponent();
            //Touch.FrameReported += this.Touch_FrameReported;
        }

        public enum orientation {Horizontal, Vertical};
        public enum dir {Minus, Plus};
        public orientation ScrollOrientation { get; set; }

        double pos;

        private void LayoutRoot_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            e.Handled = true;
            if (ScrollOrientation.Equals(orientation.Horizontal))
                pos = e.GetPosition(null).X;
            else
                pos = e.GetPosition(null).Y;
        }

        private void LayoutRoot_MouseMove(object sender, MouseEventArgs e)
        {
            if (ScrollOrientation.Equals(orientation.Vertical))
            {
                if (OnScrolled != null)
                    OnScrolled(this.ScrollOrientation, e.GetPosition(null).Y > pos ? dir.Plus : dir.Minus);
            }
            else
            {
                if (OnScrolled != null)
                    OnScrolled(this.ScrollOrientation, e.GetPosition(null).X > pos ? dir.Plus : dir.Minus);
            }
        }

    }
}
