#-------------------------------------------------
#
# Project created by QtCreator 2010-11-16T15:24:02
#
#-------------------------------------------------

QT       += core gui declarative

TARGET = QtQuickQML11
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ofono.cpp \

OTHER_FILES += \
    qml/QtQuickQML1.qml \
    qml/QtQmlPhoneApplication.qml \
    qml/ButtonUI.qml \
    images/Save.png \
    js/Helper.js

HEADERS += \
    ofono.h
