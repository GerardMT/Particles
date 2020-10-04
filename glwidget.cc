#include "glwidget.h"
#include "particle_initializer_fountain.h"
#include "particle_initializer_waterfall.h"
#include "solver_euler.h"
#include "solver_implicit_euler.h"

#include <QTimer>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

GLWidget::~GLWidget()
{
    for (auto o : objects_) {
        delete o;
    }

    delete solver_euler_;
    delete solver_implicit_euler_;

    delete particle_initializer_fountain_;
    delete particle_initializer_waterfall_;

    delete particles_system_;
}


void GLWidget::initializeGL()
{
    solver_euler_ = new SolverEuler();
    solver_implicit_euler_ = new SolverImplicitEuler();

    particle_initializer_fountain_ = new ParticleInitializerFountain(glm::vec3(0.0, 0.5, 0.0));
    particle_initializer_waterfall_ = new ParticleInitializerWaterfall(glm::vec3(0.0, 0.5, 0.0));

    particles_system_ = new ParticleSystem(*solver_euler_, *particle_initializer_fountain_, 100);
    paint_gl_.push_back(particles_system_);

    camera_.pos_ = glm::vec3(5.0, 5.0, 5.0);
    camera_.lookAt(glm::vec3(0.0, 0.0, 0.0));

    glewInit();

    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);

    for (auto p : paint_gl_) {
        p->initialieGL();
    }

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1.0 / 60.0 * 1000.0);
}

void GLWidget::resizeGL(int w, int h)
{
    camera_.width_ = w;
    camera_.height_ = h;
}

void GLWidget::paintGL() {
    chrono::steady_clock::time_point time_now = chrono::steady_clock::now();
    float dt = chrono::duration_cast<chrono::nanoseconds>(time_last_ - time_now).count() * 1e-9;

    camera_.viewport();
    camera_.compute_view_projection();

    for (auto p : paint_gl_) {
        p->paintGL(dt, camera_);
    }

    time_last_ = time_now;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLWidget::uiSolverEuler(bool v)
{
    if (v) {
        particles_system_->solver(*solver_euler_);
    }
}

void GLWidget::uiSolverImplicitEuler(bool v)
{
    if (v) {
        particles_system_->solver(*solver_implicit_euler_);
    }
}

void GLWidget::uiParticleInitializerFountain(bool v)
{
    if (v) {
        particles_system_->particleInitializer(*particle_initializer_fountain_);
    }
}

void GLWidget::uiParticleInitializerWatterfall(bool v)
{
    if (v) {
        particles_system_->particleInitializer(*particle_initializer_waterfall_);
    }
}
