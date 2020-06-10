#-------------------------------------------------
#
# Project created by QtCreator 2020-06-06T13:42:52
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PJC_obiektowe_szachy_103
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        figury.cpp/figura.cpp \
        figury.cpp/figura_z_ogranieczniami.cpp \
        figury.cpp/goniec.cpp \
        figury.cpp/krol.cpp \
        figury.cpp/krolowa.cpp \
        figury.cpp/pionek.cpp \
        figury.cpp/skoczek.cpp \
        figury.cpp/wieza.cpp \
        gra_control.cpp \
        gra_model.cpp \
        gra_view.cpp \
        gracz.cpp \
        ludzkigracz.cpp \
        main.cpp \
        menu.cpp \
        mylabel.cpp \
        network.cpp/client_mode.cpp \
        network.cpp/gra_network.cpp \
        network.cpp/server_mode.cpp \
        plansza.cpp \
        pole.cpp \
        ruch.cpp \
        silnikszachowy.cpp \
        wczytanie_fen.cpp \
        wybor_figury.cpp

HEADERS += \
        figury.h/figura.h \
        figury.h/figura_z_ogranieczniami.h \
        figury.h/goniec.h \
        figury.h/krol.h \
        figury.h/krolowa.h \
        figury.h/pionek.h \
        figury.h/skoczek.h \
        figury.h/wieza.h \
        gra_control.h \
        gra_model.h \
        gra_view.h \
        gracz.h \
        ludzkigracz.h \
        menu.h \
        mylabel.h \
        network.h/client_mode.h \
        network.h/gra_network.h \
        network.h/server_mode.h \
        plansza.h \
        pole.h \
        ruch.h \
        silnikszachowy.h \
        wczytanie_fen.h \
        wybor_figury.h

FORMS += \
        gra_control.ui \
        menu.ui \
        wczytanie_fen.ui \
        wybor_figury.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
