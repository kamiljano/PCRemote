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
using System.IO.IsolatedStorage;
using System.Xml.Serialization;
using System.Collections.Generic;
using System.IO;

namespace PCRemoteWP.storage
{
    public static class ConfigStorage
    {

        private const string filename = @"config.xml";

        private static ConfigData instance;

        public static ConfigData Instance
        {
            get
            {
                if (instance == null)
                {
                    try
                    {
                        LoadInstance();
                    }
                    catch
                    {
                        instance = new ConfigData();
                    }
                }
                return instance;
            }
        }

        private static void LoadInstance()
        {
            IsolatedStorageFile myStore = IsolatedStorageFile.GetUserStoreForApplication();
            XmlSerializer deserializer = new XmlSerializer(typeof(List<ConfigData>));
            List<ConfigData> configs;
            using (var isoFileStream = new IsolatedStorageFileStream(filename, FileMode.Open, myStore))
            {
                configs = (List<ConfigData>)deserializer.Deserialize(isoFileStream);
            }
            instance = configs[0];
        }

        public static void Save()
        {
            if (instance != null)
            {
                var ss = new List<ConfigData>();
                ss.Add(instance);
                IsolatedStorageFile myStore = IsolatedStorageFile.GetUserStoreForApplication();

                XmlSerializer serializer = new XmlSerializer(typeof(List<ConfigData>));
                using (var isoFileStream = new IsolatedStorageFileStream(filename, FileMode.OpenOrCreate, myStore))
                {
                    serializer.Serialize(isoFileStream, ss);
                }
            }
        }
    }
}
