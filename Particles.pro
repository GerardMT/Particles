QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Particles
TEMPLATE = app

CONFIG += c++14
CONFIG(release, release|debug):QMAKE_CXXFLAGS += -Wall -O2

CONFIG(release, release|debug):DESTDIR = release/
CONFIG(release, release|debug):OBJECTS_DIR = release/
CONFIG(release, release|debug):MOC_DIR = release/
CONFIG(release, release|debug):UI_DIR = release/

CONFIG(debug, release|debug):DESTDIR = debug/
CONFIG(debug, release|debug):OBJECTS_DIR = debug/
CONFIG(debug, release|debug):MOC_DIR = debug/
CONFIG(debug, release|debug):UI_DIR = debug/

INCLUDEPATH += /usr/include/eigen3/

LIBS += -lGLEW

SOURCES += \
    main.cc \
    main_window.cc \
    glwidget.cc

HEADERS  += \
    main_window.h \
    glwidget.h

FORMS    += \
    main_window.ui

OTHER_FILES +=

DISTFILES += \
    shaders/phong.frag \
    shaders/phong.vert


