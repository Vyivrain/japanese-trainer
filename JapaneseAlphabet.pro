#-------------------------------------------------
#
# Project created by QtCreator 2015-02-22T09:59:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JapaneseAlphabet
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    alphabet.cpp

HEADERS  += widget.h \
    alphabet.h

FORMS    += widget.ui

QMAKE_CXXFLAGS += -std=c++11
