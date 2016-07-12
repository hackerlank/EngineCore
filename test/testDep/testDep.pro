
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../src/EngineCoreLib/release/ -lEngineCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../src/EngineCoreLib/debug/ -lEngineCore
else:unix: LIBS += -L$$OUT_PWD/../../src/EngineCoreLib/ -lEngineCore

INCLUDEPATH += $$PWD/../../src/EngineCoreLib
DEPENDPATH += $$PWD/../../src/EngineCoreLib

