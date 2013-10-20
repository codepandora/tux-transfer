TEMPLATE = app
QT += widgets
INCLUDEPATH += "/usr/local/include/boost"      #Path to Boost installation headers
LIBS += -L"/usr/local/lib" -lboost_thread -lboost_system #Path to Boost installation Libraries
HEADERS += includes/TuxTray.h \
	   		includes/tuxCopy.h \
	   		includes/tuxMove.h \
	   		includes/CopyInstance.h \
	   		includes/ProgressTracker.h \
	   		includes/threadPool.h
SOURCES += main.cpp \
           src/TuxTray.cpp \
           src/TuxCopy.cpp \
	   		src/TuxMove.cpp \
	   		src/CopyInstance.cpp \
	   		src/ProgressTracker.cpp \
	   		src/threadPool.cpp 
RESOURCES = assets.qrc
OBJECTS_DIR = obj
TARGET = TuxTransfer
