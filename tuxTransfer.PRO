TEMPLATE = app
QT += gui
INCLUDEPATH += "/usr/include/boost"        #Path to Boost installation headers
LIBS += -L"/usr/lib" -lboost_thread -lboost_system #Path to Boost installation Libraries
HEADERS += includes/TuxTray.h \
	   		includes/tuxCopy.h \
	   		includes/tuxMove.h \
	   		includes/CopyInstance.h \
	   		includes/threadPool.h
SOURCES += main.cpp \
           src/TuxTray.cpp \
           src/TuxCopy.cpp \
	   		src/TuxMove.cpp \
	   		src/CopyInstance.cpp \
	   		src/threadPool.cpp \
	   		tuxTransfer.cpp 
RESOURCES = assets.qrc
OBJECTS_DIR = obj
TARGET = TuxTransfer
