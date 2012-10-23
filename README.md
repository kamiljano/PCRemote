PCRemote (All rights reserved to Kamil Janowski; 2012)
========

PCRemote is a project consisting of 3 applications: server (C++, Qt, WinAPI) and two clients (one for Android 2.2 and one for Windows Phone 7)
Clients connect to server and take the control over the cursor and keyboard of a host PC.

If you're interested, you can read more at /Documentation/Documentation.docx

This is supposed to be part of my bachelor thesis project I will present in January 2012 at Cracow University of Technology (Poland).

BTW
Please, don't blame me for using WinAPI in a Qt application. The reason is simply because neither Qt nor Ubuntu's (the linux distribution I use) native API supports simulation of keyboard or mouse clicks.