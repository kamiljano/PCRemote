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
using System.ComponentModel;

namespace PCRemoteWP.storage
{
    public class ConfigData : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        public ConfigData()
        {
            ScrollSensitivity = 10;
            MouseSensitivity = 0.5f;
            TimeToRightClick = 1500;
        }

        public ConfigData(byte scrollSens, float mouseSens, int timeRightClick)
        {
            this.ScrollSensitivity = scrollSens;
            this.MouseSensitivity = mouseSens;
            this.TimeToRightClick = timeRightClick;
        }

        private byte scrollSens;
        public byte ScrollSensitivity
        {
            get
            {
                return scrollSens;
            }
            set
            {
                scrollSens = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("ScrollSensitivity"));
            }
        }

        private float mouseSens;
        public float MouseSensitivity
        {
            get
            {
                return mouseSens;
            }
            set
            {
                mouseSens = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("MouseSensitivity"));
            }
        }

        private int ttrc;
        public int TimeToRightClick
        {
            get
            {
                return ttrc;
            }
            set
            {
                ttrc = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("TimeToRightClick"));
            }
        }
    }
}
