﻿#pragma checksum "D:\MyFiles\code\PCRemote\PCRemoteWP\PCRemoteWP\pages\NewServerPage.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "DB12437E6AF6EE3D0CBA79F348A97995"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.17929
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using Microsoft.Phone.Controls;
using System;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Resources;
using System.Windows.Shapes;
using System.Windows.Threading;


namespace PCRemoteWP.pages {
    
    
    public partial class Servers : Microsoft.Phone.Controls.PhoneApplicationPage {
        
        internal System.Windows.Controls.Grid LayoutRoot;
        
        internal System.Windows.Controls.StackPanel stackPanel1;
        
        internal System.Windows.Controls.TextBlock textBlock1;
        
        internal System.Windows.Controls.TextBox tName;
        
        internal System.Windows.Controls.TextBlock textBlock2;
        
        internal System.Windows.Controls.TextBox tAddress;
        
        internal System.Windows.Controls.TextBlock textBlock3;
        
        internal System.Windows.Controls.TextBox tPort;
        
        internal System.Windows.Controls.Button button1;
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Windows.Application.LoadComponent(this, new System.Uri("/PCRemoteWP;component/pages/NewServerPage.xaml", System.UriKind.Relative));
            this.LayoutRoot = ((System.Windows.Controls.Grid)(this.FindName("LayoutRoot")));
            this.stackPanel1 = ((System.Windows.Controls.StackPanel)(this.FindName("stackPanel1")));
            this.textBlock1 = ((System.Windows.Controls.TextBlock)(this.FindName("textBlock1")));
            this.tName = ((System.Windows.Controls.TextBox)(this.FindName("tName")));
            this.textBlock2 = ((System.Windows.Controls.TextBlock)(this.FindName("textBlock2")));
            this.tAddress = ((System.Windows.Controls.TextBox)(this.FindName("tAddress")));
            this.textBlock3 = ((System.Windows.Controls.TextBlock)(this.FindName("textBlock3")));
            this.tPort = ((System.Windows.Controls.TextBox)(this.FindName("tPort")));
            this.button1 = ((System.Windows.Controls.Button)(this.FindName("button1")));
        }
    }
}
