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
    	fcFallingCircle.cpp \
    	fcFallingObjectGL.cpp \
        fcFallingCircleGL.cpp \
        fcGameField.cpp \
        fcGameEngine.cpp \
        fcUtilities.cpp \
        fcGameFieldGL.cpp \
        fcFallingObject.cpp

HEADERS  += fcMainWindow.h \
    	fcRendererGL.h \
    	fcFallingObject.h \
    	fcFallingCircle.h \
    	fcFallingObjectGL.h \
        fcFallingCircleGL.h \
        fcGameField.h \
        fcGameEngine.h \
        fcGameSettings.h \
        fcUtilities.h \
        fcGameFieldGL.h
