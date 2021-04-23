QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = particles
TEMPLATE = app

CONFIG += c++14
CONFIG(release, release|debug):QMAKE_CXXFLAGS += -Wall -O2

CONFIG(release, release|debug):DESTDIR = ../build/release/
CONFIG(release, release|debug):OBJECTS_DIR = ../build/release/
CONFIG(release, release|debug):MOC_DIR = ../build/release/
CONFIG(release, release|debug):UI_DIR = ../build/release/

CONFIG(debug, release|debug):DESTDIR = ../build/debug/
CONFIG(debug, release|debug):OBJECTS_DIR = ../build/debug/
CONFIG(debug, release|debug):MOC_DIR = ../build/debug/
CONFIG(debug, release|debug):UI_DIR = ../build/debug/

INCLUDEPATH += /usr/include/eigen3/

LIBS += -lGLEW

SOURCES += \
    camera.cpp \
    collider_plane.cpp \
    collider_polygon.cpp \
    collider_sphere.cpp \
    collider_triangle.cpp \
    force_field_drag.cpp \
    force_field_gravity.cpp \
    main.cc \
    main_window.cc \
    glwidget.cc \
    mesh.cpp \
    object.cpp \
    particle.cpp \
    particle_initializer_fountain.cpp \
    particle_initializer_semi_sphere.cpp \
    particle_initializer_waterfall.cpp \
    particle_system.cpp \
    solver_euler.cpp \
    solver_semi_implicit_euler.cpp \
    solver_verlet.cpp \
    util.cpp

HEADERS  += \
    Transform.h \
    camera.h \
    collider.h \
    collider_plane.h \
    collider_polygon.h \
    collider_sphere.h \
    collider_triangle.h \
    force_field.h \
    force_field_drag.h \
    force_field_gravity.h \
    main_window.h \
    glwidget.h \
    mesh.h \
    object.h \
    paint_gl.h \
    particle.h \
    particle_initializer.h \
    particle_initializer_fountain.h \
    particle_initializer_semi_sphere.h \
    particle_initializer_waterfall.h \
    particle_system.h \
    solver.h \
    solver_euler.h \
    solver_semi_implicit_euler.h \
    solver_verlet.h \
    util.h

FORMS    += \
    main_window.ui

RESOURCES += \
    ../res/shader/particle.frag \
    ../res/shader/particle.vert \
    ../res/shader/object.frag \
    ../res/shader/object.vert