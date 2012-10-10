#-------------------------------------------------
#
# Project created by QtCreator 2012-08-26T15:34:59
#
#-------------------------------------------------

QT       += core gui \
            network

TARGET = PCRemote
TEMPLATE = app

win32{
LIBS += "C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Lib\user32.lib" \
        "C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Lib\Shell32.lib"
}

SOURCES += main.cpp\
        mainwindow.cpp \
    tray.cpp \
    communicators/abstractcommunicator.cpp \
    communicators/tcpcommunicator.cpp \
    slidingwindow.cpp \
    messagewindow.cpp \
    Widgets/clientsview.cpp \
    Widgets/mediaserver.cpp \
    aboutdialog.cpp \
    configdialog.cpp \
    Widgets/mediacontroller.cpp

HEADERS  += mainwindow.h \
    communicators/abstractcommunicator.h \
    communicators/tcpcommunicator.h \
    slidingwindow.h \
    messagewindow.h \
    tray.h \
    Widgets/clientsview.h \
    Widgets/mediaserver.h \
    ../server_plugin/server_plugin/server_plugin.h \
    aboutdialog.h \
    configdialog.h \
    Widgets/mediacontroller.h \
    export/ServerMediaPlugin.h

RESOURCES += \
    ResImages.qrc

FORMS += \
    aboutdialog.ui \
    configdialog.ui
