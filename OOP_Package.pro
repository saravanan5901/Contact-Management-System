    #-------------------------------------------------
#
# Project created by QtCreator 2020-04-06T10:37:02
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = SCTest1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    mytcpserver.cpp \
    filehandler.cpp \
    convhandler.cpp \
    contactlist.cpp \
    Contact.cpp \
    Number.cpp \
    mytcpclient.cpp

HEADERS += \
    mytcpserver.h \
    Contact.h \
    Number.h \
    contactlist.h \
    mytcpclient.h

DISTFILES += \
    README.md \
    saravanan.txt \
    classes.txt
