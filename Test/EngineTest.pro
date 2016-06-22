#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T22:29:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../EngineCoreLib.pro)

TARGET = EngineTest
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h


INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.


DISTFILES += \
    vertex.vert \
    fragment.frag \
    .gitignore \
    geo.geo

RESOURCES += \
    res.qrc
