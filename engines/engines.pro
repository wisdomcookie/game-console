TEMPLATE = app
CONFIG += console c++17
CONFIG += c++20
CONFIG -= app_bundle
CONFIG -= qt
QT       += core gui
macx: {
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15
}


win32:INCLUDEPATH += C:\QT\Tools\mingw1120_64\opt\include\ncursesw \
                     C:\QT\Tools\mingw1120_64\opt\include

win32:LIBS += C:\QT\Tools\mingw1120_64\opt\lib\libncurses.a

unix:LIBS += -lncurses

SOURCES += \
        engine.cpp \
        engine.cpp \
        main.cpp \
        robots.cpp \
        robots.cpp \
        worm.cpp

HEADERS += \
    engine.h \
    engine.h \
    robots.h \
    robots.h \
    worm.h

FORMS    += mainwindow.ui
