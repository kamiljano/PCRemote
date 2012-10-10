#-------------------------------------------------
#
# Project created by QtCreator 2012-09-26T21:08:26
#
#-------------------------------------------------

QT       -= gui

TARGET = plugin_winamp
TEMPLATE = lib

INCLUDEPATH += "../../server_plugin/server_plugin/"

LIBS += ../../server_plugin/server_plugin/debug/server_plugin.lib \
        "C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Lib\user32.lib" \

DEFINES += PLUGIN_WINAMP_LIBRARY

SOURCES += plugin_winamp.cpp

HEADERS += plugin_winamp.h\
        plugin_winamp_global.h \
    ../../server_plugin/server_plugin/server_plugin.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE09D990B
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = plugin_winamp.dll
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
