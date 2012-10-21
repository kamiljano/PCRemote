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

namespace PCRemoteWP.controls
{
    public class KeyboardButton : Button
    {
        public KeyboardButton() : base()
        {
           
        }

        protected override void OnTextInput(TextCompositionEventArgs e)
        {
            base.OnTextInput(e);
            MessageBox.Show("lol");
        }
    }
}
