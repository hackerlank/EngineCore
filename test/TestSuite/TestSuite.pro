QT += core gui widgets opengl testlib

CONFIG += c++11

TARGET = TestSuite
CONFIG += console testcase
CONFIG += staticlib

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    tst_meshtest.h \
    tst_materialtest.h \
    tst_renderabletest.h \
    tst_scenetest.h \
    tst_cameratest.h \
    tst_entitytest.h \
    tst_newtowndamper.h

unix|win32: LIBS += -L$$OUT_PWD/../../src/EngineCoreLib/ -lEngineCore

INCLUDEPATH += $$PWD/../../src/EngineCoreLib
DEPENDPATH += $$PWD/../../src/EngineCoreLib

RESOURCES += \
    res.qrc

DISTFILES += \
    torus.obj \
    box.obj
