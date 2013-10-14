TEMPLATE = app
QT += widgets
HEADERS += includes/TuxTray.h \
	   includes/tuxCopy.h
SOURCES += main.cpp \
           src/TuxTray.cpp \
           src/TuxCopy.cpp
RESOURCES = assets.qrc
OBJECTS_DIR = obj
TARGET = TuxTransfer
