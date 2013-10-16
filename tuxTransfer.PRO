TEMPLATE = app
QT += widgets
HEADERS += includes/TuxTray.h \
	   includes/tuxCopy.h \
	   includes/tuxMove.h
SOURCES += main.cpp \
           src/TuxTray.cpp \
           src/TuxCopy.cpp \
	   src/TuxMove.cpp
RESOURCES = assets.qrc
OBJECTS_DIR = obj
TARGET = TuxTransfer
