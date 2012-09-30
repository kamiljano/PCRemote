﻿using System;
using System.Collections.Generic;
using System.Xml;
using System.Xml.Serialization;
using System.IO;
using System.IO.IsolatedStorage;

namespace PCRemoteWP
{
    public class ServersStorage
    {
        private const string filename = @"servers.xml";

        private static List<ServerData> ss;

        public static List<ServerData> Servers {
            get
            {
                if (ss == null)
                {
                    try
                    {
                        DeserializeFromXML();
                    }
                    catch
                    {
                        ss = new List<ServerData>();
                    }
                }
                return ss;
            }
        }

        /// <summary>
        /// Saves all the information about available servers
        /// Might throw exception if serialization fails
        /// </summary>
        public static void Save()
        {
            if (ss != null && ss.Count > 0)
                SerializeToXML();
        }

        private static void SerializeToXML()
        {
            IsolatedStorageFile myStore = IsolatedStorageFile.GetUserStoreForApplication();

            XmlSerializer serializer = new XmlSerializer(typeof(List<ServerData>));
            //TextWriter textWriter = new StreamWriter(filename);
            using (var isoFileStream = new IsolatedStorageFileStream(filename, FileMode.OpenOrCreate, myStore))
            {
                serializer.Serialize(isoFileStream, ss);
            }
            //textWriter.Close();
        }

        private static void DeserializeFromXML()
        {
            IsolatedStorageFile myStore = IsolatedStorageFile.GetUserStoreForApplication();
            XmlSerializer deserializer = new XmlSerializer(typeof(List<ServerData>));
            //TextReader textReader = new StreamReader(filename);
            List<ServerData> servers;
            using (var isoFileStream = new IsolatedStorageFileStream(filename, FileMode.Open, myStore))
            {
                servers = (List<ServerData>)deserializer.Deserialize(isoFileStream);
            }
            //textReader.Close();
            ss = servers;
        }

        public static ServerData SelectedServer { set; get; }
    }
}
