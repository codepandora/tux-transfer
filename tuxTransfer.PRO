TARGET = TuxTransfer
TE += app
INCLUDEPATH += "/usr/local/include/boost"        #Path to Boost installation headers
LIBS += -L"/usr/local/lib" -lboost_thread -lboost_system #Path to Boost installation Libraries
SOURCES = src/CopyInstance.cpp src/threadPool.cpp
HEADERS = includes/CopyInstance.h includes/threadPool.h
TARGET = ThreadPoolEx
