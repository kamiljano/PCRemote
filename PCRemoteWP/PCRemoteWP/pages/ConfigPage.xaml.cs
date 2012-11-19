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
using Microsoft.Phone.Controls;
using PCRemoteWP.storage;

namespace PCRemoteWP.pages
{
    public partial class ConfigPage : PhoneApplicationPage
    {
        public ConfigPage()
        {
            InitializeComponent();
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            ConfigData cd = ConfigStorage.Instance;
            slider1.Value = cd.MouseSensitivity;
            slider2.Value = cd.ScrollSensitivity;
            slider3.Value = cd.TimeToRightClick;
        }

        protected override void OnNavigatedFrom(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedFrom(e);
            ConfigData cd = ConfigStorage.Instance;
            cd.MouseSensitivity = (float)slider1.Value;
            cd.ScrollSensitivity = (byte)slider2.Value;
            cd.TimeToRightClick = (int)slider3.Value;
            ConfigStorage.Save();
        }
    }
}