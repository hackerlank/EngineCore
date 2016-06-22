#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T21:40:04
#
#-------------------------------------------------

QT       += opengl

TARGET = EngineCore
TEMPLATE = lib
#CONFIG += staticlib

SOURCES += \
    $$PWD/mesh/normal3dmesh.cpp \
    $$PWD/mesh/primitivemesh.cpp \
    $$PWD/Primitives/shapegenerator.cpp \
    $$PWD/entity.cpp \
    $$PWD/material.cpp \
    $$PWD/renderable.cpp \
    $$PWD/scene.cpp \
    $$PWD/light.cpp \
    $$PWD/camera.cpp \
    $$PWD/mesh.cpp \
    $$PWD/meshnormal.cpp



HEADERS += \
    $$PWD/Primitives/vertex.h \
    $$PWD/mesh/normal3dmesh.h \
    $$PWD/mesh/primitivemesh.h \
    $$PWD/Primitives/shapedata.h \
    $$PWD/Primitives/shapegenerator.h \
    $$PWD/Primitives/vertex.h \
    $$PWD/entity.h \
    $$PWD/material.h \
    $$PWD/mesh.h \
    $$PWD/renderable.h \
    $$PWD/scene.h \
    $$PWD/light.h \
    $$PWD/camera.h \
    $$PWD/meshnormal.h

unix {
   target.path = /home/oliver/.lib
   INSTALLS += target
}

DISTFILES += \
    LICENSE \
    README.md
