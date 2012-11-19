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
using System.Threading;

namespace PCRemoteWP.controls
{
    public partial class MousePad : UserControl
    {
        public delegate void MouseMoveDelegate(sbyte x, sbyte y);
        public event MouseMoveDelegate OnMouseMoveEvent;
        public delegate void ClickDelegate();
        public event ClickDelegate OnLeftClick;
        public event ClickDelegate OnRightClick;
        public event ClickDelegate OnLeftDown;
        public event ClickDelegate OnLeftUp;
        private double last_x, last_y;
        private int steps;
        private DateTime lastDown, lastUp;
        private bool isDown = false;
        private bool selecting = false;

        public MousePad()
        {
            InitializeComponent();
        }

        private void LayoutRoot_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            Point p = e.GetPosition(null);
            last_x = p.X;
            last_y = p.Y;
        }

        private void LayoutRoot_MouseMove(object sender, MouseEventArgs e)
        {
            Point p = e.GetPosition(null);
            
            if (OnMouseMoveEvent != null)
                OnMouseMoveEvent((sbyte)(MouseController.MouseSensitivity * (p.X - this.last_x)), (sbyte)(MouseController.MouseSensitivity * (p.Y - this.last_y)));

            last_x = p.X;
            last_y = p.Y;
            steps ++;
        }

        private void UserControl_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            e.Handled = true;
            steps = 0;
            lastDown = DateTime.Now;
            isDown = true;
            if ((DateTime.Now - lastUp).TotalMilliseconds < 300)
            {
                selecting = true;
                if (OnLeftDown != null)
                    OnLeftDown();
            }
            else
            {
                Thread t = new Thread(RightClickThread);
                t.Start();
            }
        }

        private void RightClickThread()
        {
            try
            {
                Thread.Sleep(MouseController.TimeToRightClick);
            }
            catch { }
            if (OnRightClick != null && isDown && steps < 4 && (DateTime.Now - lastDown).TotalMilliseconds >= MouseController.TimeToRightClick)
                OnRightClick();
        }

        private void UserControl_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            e.Handled = true;
            isDown = false;
            lastUp = DateTime.Now;
            if (selecting)
            {
                selecting = false;
                if (OnLeftUp != null)
                    OnLeftUp();
            }
            else if (OnLeftClick != null && steps < 5 && (DateTime.Now - lastDown).TotalMilliseconds < MouseController.TimeToRightClick)
                OnLeftClick();
        }
    }
}
