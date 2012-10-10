﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PCRemoteWP.messages
{
    public enum Protocol { TCP, UDP }

    interface NetworkMessage
    {
        byte[] Message() ;

        Protocol NetworkProtocol { get; }
    }
}