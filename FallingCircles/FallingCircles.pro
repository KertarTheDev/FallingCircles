#-------------------------------------------------
#
# Project created by QtCreator 2013-06-04T22:04:24
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FallingCircles
TEMPLATE = app


SOURCES += main.cpp\
        fcMainWindow.cpp \
	    fcRendererGL.cpp \
    fcFallingCircle.cpp

HEADERS  += fcMainWindow.h \
    	fcRendererGL.h \
    	fcFallingObject.h \
    fcFallingCircle.h
