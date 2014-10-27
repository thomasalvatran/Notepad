#-------------------------------------------------
#
# Project created by QtCreator 2014-10-08T18:32:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notepad
TEMPLATE = app


SOURCES += main.cpp\
        notepad.cpp \
    mydialog.cpp

HEADERS  += notepad.h \
    mydialog.h

FORMS    += notepad.ui \
    mydialog.ui

RESOURCES += \
    AppResources.qrc
