TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Piezas.cpp \
        Sistema.cpp \
        Tablero.cpp \
        main.cpp

HEADERS += \
    Sistema.h \
    Tablero.h \
    piezas.h
