#-------------------------------------------------
#
# Project created by QtCreator 2016-07-22T23:41:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_EVE_Box
TEMPLATE = app

RC_FILE += eve.rc

SOURCES += main.cpp\
        sign_in.cpp \
    mainwindow.cpp \
    registerdialog.cpp \
    mysql.cpp

HEADERS  += sign_in.h \
    mainwindow.h \
    registerdialog.h \
    mysql.h

FORMS    += sign_in.ui \
    mainwindow.ui \
    registerdialog.ui

RESOURCES += \
    eves.qrc
