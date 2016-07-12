#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T22:29:22
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += testcase
TEMPLATE = app


SOURCES += \ #$$PWD/main.cpp\
    $$PWD/testmesh.cpp
        #$$PWD/mainwindow.cpp

HEADERS  += #$$PWD/mainwindow.h


INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.


DISTFILES += \
    #$$PWD/vertex.vert \
    #$$PWD/fragment.frag \
    #$$PWD/.gitignore \

RESOURCES += \
    $$PWD/res.qrc
