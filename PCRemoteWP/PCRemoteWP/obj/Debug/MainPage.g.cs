﻿#pragma checksum "D:\MyFiles\code\PCRemote\PCRemoteWP\PCRemoteWP\MainPage.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "7C55B00B2E08AA18A3D3F75F6779263E"
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


namespace PCRemoteWP {
    
    
    public partial class MainPage : Microsoft.Phone.Controls.PhoneApplicationPage {
        
        internal System.Windows.Controls.Grid LayoutRoot;
        
        internal System.Windows.Controls.Button bremote;
        
        internal System.Windows.Controls.Button bconfig;
        
        internal System.Windows.Controls.Button bserver;
        
        internal System.Windows.Controls.Button bhelp;
        
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
            System.Windows.Application.LoadComponent(this, new System.Uri("/PCRemoteWP;component/MainPage.xaml", System.UriKind.Relative));
            this.LayoutRoot = ((System.Windows.Controls.Grid)(this.FindName("LayoutRoot")));
            this.bremote = ((System.Windows.Controls.Button)(this.FindName("bremote")));
            this.bconfig = ((System.Windows.Controls.Button)(this.FindName("bconfig")));
            this.bserver = ((System.Windows.Controls.Button)(this.FindName("bserver")));
            this.bhelp = ((System.Windows.Controls.Button)(this.FindName("bhelp")));
        }
    }
}

