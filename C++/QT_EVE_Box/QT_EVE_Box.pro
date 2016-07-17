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
    sign_in.cpp

RC_FILE += eve.rc

HEADERS  += mainwindow.h \
    sign_in.h \

FORMS    += mainwindow.ui \
    sign_in.ui

RESOURCES += \
    eve.rc \
    eves.qrc

#INCLUDEPATH += "C:/mysql-5.7.11-winx64/include"

#LIBS += "C:/mysql-5.7.11-winx64/lib/libmysql.lib"
