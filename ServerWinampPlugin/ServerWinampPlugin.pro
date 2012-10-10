#-------------------------------------------------
#
# Project created by QtCreator 2012-10-10T20:25:05
#
#-------------------------------------------------

#QT       -= gui

TARGET = ServerWinampPlugin
TEMPLATE = lib

INCLUDEPATH += ../PCRemoteWin/export/

LIBS += "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/user32.lib"

DEFINES += SERVERWINAMPPLUGIN_LIBRARY

SOURCES += serverwinampplugin.cpp

HEADERS += serverwinampplugin.h\
        ServerWinampPlugin_global.h \
        ../PCRemoteWin/export/ServerMediaPlugin.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE4F4C615
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = ServerWinampPlugin.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
