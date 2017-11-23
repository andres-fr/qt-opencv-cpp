SOURCES += WEBCAM.cpp
HEADERS += design.h
CONFIG += c++11
TARGET = webcam
QT += widgets gui
LIBS += `pkg-config --cflags --libs opencv`
