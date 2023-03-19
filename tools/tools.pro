TEMPLATE = app
CONFIG += console c++17
CONFIG += c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        baseclass.cpp \
        config.cpp \
        log.cpp \
        main.cpp

HEADERS += \
    baseclass.h \
    config.h \
    log.h \
    macro.h
