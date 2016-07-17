#-------------------------------------------------
#
# Project created by QtCreator 2016-06-29T21:59:19
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_EVE_Box
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sign_in.cpp \
    registerdialog.cpp

RC_FILE += eve.rc

HEADERS  += mainwindow.h \
    sign_in.h \
    registerdialog.h

FORMS    += mainwindow.ui \
    sign_in.ui \
    registerdialog.ui

RESOURCES += \
    eve.rc \
    eves.qrc

DISTFILES +=
