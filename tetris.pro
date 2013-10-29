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
    model/GameController.cpp

HEADERS  += mainwindow.h \
    view/tetriswidget.h \
    presenter/presenter.h \
    view/iview.h \
    model/GameController.h

FORMS    += mainwindow.ui
