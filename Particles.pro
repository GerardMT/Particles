QT += core gui opengl

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
    force_field_gravity.cpp \
    main.cc \
    main_window.cc \
    glwidget.cc \
    mesh.cpp \
    object.cpp \
    particle.cpp \
    particle_initializer.cpp \
    particle_initializer_fountain.cpp \
    particle_initializer_waterfall.cpp \
    particle_system.cpp \
    solver_euler.cpp \
    solver_implicit_euler.cpp \
    util.cpp

HEADERS  += \
    camera.h \
    collider.h \
    force_field.h \
    force_field_gravity.h \
    main_window.h \
    glwidget.h \
    mesh.h \
    object.h \
    paint_gl.h \
    particle.h \
    particle_initializer.h \
    particle_initializer_fountain.h \
    particle_initializer_waterfall.h \
    particle_system.h \
    solver.h \
    solver_euler.h \
    solver_implicit_euler.h \
    util.h

FORMS    += \
    main_window.ui

RESOURCES += \
    shader/particle.frag \
    shader/particle.vert

DISTFILES += \
    shader/object.frag \
    shader/object.vert
