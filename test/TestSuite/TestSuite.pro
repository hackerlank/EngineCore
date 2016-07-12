QT += core testlib

CONFIG += c++11

TARGET = TestSuite
CONFIG += console testcase

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    tst_meshtest.h \
    tst_materialtest.h

unix|win32: LIBS += -L$$OUT_PWD/../../src/EngineCoreLib/ -lEngineCore

INCLUDEPATH += $$PWD/../../src/EngineCoreLib
DEPENDPATH += $$PWD/../../src/EngineCoreLib

RESOURCES += \
    res.qrc

DISTFILES += \
    torus.obj \
    box.obj
