#-------------------------------------------------
#
# Project created by QtCreator 2016-07-12T18:30:52
#
#-------------------------------------------------

QT       += testlib opengl


TARGET = tst_meshtest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += testcase
TEMPLATE = app


SOURCES += tst_meshtest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

include(../testDep/testDep.pro)

RESOURCES += \
    res.qrc

DISTFILES +=


