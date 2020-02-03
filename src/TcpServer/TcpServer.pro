#-------------------------------------------------
#
# Project created by QtCreator 2017-01-27T16:00:18
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bme280Server

TEMPLATE = lib
DESTDIR = ../../lib

DEFINES += BME280SERVER_LIBRARY

SOURCES += \
    bme280Server.cpp

HEADERS  += \
    bme280Server.h \
    bme280Server_global.h

