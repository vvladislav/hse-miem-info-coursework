######################################################################
# Automatically generated by qmake (3.1) Wed Oct 31 21:09:36 2018
######################################################################

TEMPLATE = app
TARGET = strategy
QT += gui widgets
INCLUDEPATH += src/ src/game_process src/objects .
DESTDIR = bin/
mkswp.target = .tmp
mkswp.commands = mkdir
QT_EXTRA_TARGET += mktmp
unix{
TARGET = strategy.out
}
else{
TARGET = strategy.exe
}
OBJECTS_DIR = .tmp

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += src/All-include.h \
           src/game_process/Game.h \
           src/game_process/Map.h \
           src/game_process/Place.h \
           src/game_process/Player.h \
           src/objects/AttackingObject.h \
           src/objects/Building.h \
           src/objects/DestroyableObject.h \
           src/objects/MovingObject.h \
           src/objects/ResourceObject.h \
           src/objects/SimpleObject.h \
           src/objects/Terrain.h \
           src/objects/Unit.h
SOURCES += src/main.cpp \
           src/game_process/Map.cpp \
           src/game_process/Place.cpp \
           src/game_process/Player.cpp \
           src/objects/AttackingObject.cpp \
           src/objects/Building.cpp \
           src/objects/DestroyableObject.cpp \
           src/objects/MovingObject.cpp \
           src/objects/ResourceObject.cpp \
           src/objects/SimpleObject.cpp \
           src/objects/Terrain.cpp \
           src/objects/Unit.cpp
