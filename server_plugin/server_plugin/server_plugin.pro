#-------------------------------------------------
#
# Project created by QtCreator 2012-09-26T21:20:13
#
#-------------------------------------------------

QT       -= gui

TARGET = server_plugin
TEMPLATE = lib
CONFIG += staticlib

SOURCES += server_plugin.cpp

HEADERS += server_plugin.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
