# -------------------------------------------------
# Project created by QtCreator 2010-04-10T17:17:42
# -------------------------------------------------
QT -= core \
    gui
TARGET = ENet++
TEMPLATE = lib
CONFIG += staticlib
SOURCES += src/Peer.cpp \
    src/Packet.cpp \
    src/Host.cpp \
    src/Event.cpp \
    src/ENet.cpp \
    src/Address.cpp
HEADERS += include/enetpp/Peer.h \
    include/enetpp/Packet.h \
    include/enetpp/Host.h \
    include/enetpp/Event.h \
    include/enetpp/ENet.h \
    include/enetpp/Address.h
LIBS += -L../enet \
    -lenet
INCLUDEPATH += ../enet/include ./include
