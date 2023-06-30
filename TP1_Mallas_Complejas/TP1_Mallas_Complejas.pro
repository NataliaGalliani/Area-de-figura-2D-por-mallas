TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    malla_compleja.cpp \
    punto.cpp \
    malla_elemental.cpp \
    lista.cpp \
    str_nodo.cpp

HEADERS += \
    malla_compleja.h \
    punto.h \
    malla_elemental.h \
    lista.h \
    str_nodo.h
