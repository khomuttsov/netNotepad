#-------------------------------------------------
#
# Project created by QtCreator 2015-07-26T00:11:35
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    user.cpp \
    server.cpp \
    textcorefunc.cpp

HEADERS  += mainwindow.h \
    user.h \
    server.h \
    textcorefunc.h

FORMS    += mainwindow.ui
