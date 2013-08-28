CONFIG+=qt
TEMPLATE = app
QT += widgets
HEADERS += src/TuxTray.h
SOURCES += main.cpp \
           src/TuxTray.cpp
RESOURCES = assets.qrc
OBJECTS_DIR = obj
TARGET = TuxTransfer
