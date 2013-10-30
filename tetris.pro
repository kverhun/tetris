#-------------------------------------------------
#
# Project created by QtCreator 2013-10-27T23:10:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tetris
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    presenter/presenter.cpp \
    model/GameController.cpp \
    model/Figure.cpp \
    model/Field.cpp \
    model/State.cpp \
    model/Game.cpp \
    model/LayoutState.cpp \
    view/tetriswidget.cpp

HEADERS  += mainwindow.h \
    view/tetriswidget.h \
    presenter/presenter.h \
    view/iview.h \
    model/GameController.h \
    model/FieldElement.h \
    model/common.h \
    model/Figure.h \
    model/Field.h \
    model/State.h \
    model/Game.h \
    model/LayoutState.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
