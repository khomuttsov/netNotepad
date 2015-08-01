#-------------------------------------------------
#
# Project created by QtCreator 2015-07-25T23:43:58
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        notepadwindow.cpp \
    server/textcorefunc.cpp \
    server/user.cpp \
    server/server.cpp \
    texteditor.cpp

HEADERS  += notepadwindow.h \
    server/textcorefunc.h \
    server/user.h \
    server/server.h \
    texteditor.h

FORMS    += notepadwindow.ui
