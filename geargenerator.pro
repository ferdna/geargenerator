#-------------------------------------------------
#
# Project created by QtCreator 2011-12-24T23:26:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = geargenerator
TEMPLATE = app

#VER_MAJ = 1
#VER_MIN = 0
#VER_BLD = 0
#VER_REV = 22

#DEFINES += APP_VERSION=\\\"$$VER_MAJ\\.$$VER_MIN\\.$$VER_BLD\\.$$VER_REV\\\"

SOURCES += main.cpp\
        mainwindow.cpp \
    dlgconfig.cpp \
    gearobj.cpp

HEADERS  += mainwindow.h \
    dlgconfig.h \
    gearobj.h \
    globals.h

FORMS    += mainwindow.ui \
    dlgconfig.ui
