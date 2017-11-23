SOURCES += MAIN.cpp
HEADERS += design.h webcam.h
CONFIG += c++11
TARGET = main
QT += widgets gui
LIBS += `pkg-config --cflags --libs opencv`
