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
    camera.cpp \
    forcegravity.cpp \
    main.cc \
    main_window.cc \
    glwidget.cc \
    mesh.cpp \
    particle.cpp \
    particles_system.cpp \
    solver_euler.cpp \
    solver_implicit_euler.cpp \
    util.cpp

HEADERS  += \
    camera.h \
    collider.h \
    force_field.h \
    forcegravity.h \
    main_window.h \
    glwidget.h \
    mesh.h \
    particle.h \
    particles_system.h \
    solver.h \
    solver_euler.h \
    solver_implicit_euler.h \
    util.h

FORMS    += \
    main_window.ui

RESOURCES += \
    shader/particle.frag \
    shader/particle.vert
