#-------------------------------------------------
#
# Project created by QtCreator 2013-11-23T16:23:25
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestCamera
TEMPLATE = app


SOURCES += main.cpp\
        camera.cpp

HEADERS  += camera.h

FORMS    += camera.ui

CONFIG += mobility
MOBILITY = 

OTHER_FILES += \
    icon80.png \
    android/AndroidManifest.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

