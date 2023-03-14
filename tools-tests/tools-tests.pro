TEMPLATE = app
CONFIG += console c++17
CONFIG += c++20
CONFIG -= app_bundle
CONFIG -= qt
macx: {
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15
}
SOURCES += \
        main.cpp

LIBS += -pthread

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest \
                ../gtest/googletest \
                ../gtest/googletest/include \
                ../gtest/googletest/include/gtest

#HEADERS += ../tools/config.h
#SOURCES += ../tools/config.cpp
HEADERS += ../tools/log.h
SOURCES += ../tools/log.cpp
HEADERS += ../tools/baseclass.h
SOURCES += ../tools/baseclass.cpp
