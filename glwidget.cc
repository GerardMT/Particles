#include "glwidget.h"
#include "solver_euler.h"

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
    delete solver_;
    delete particles_system_;
}


void GLWidget::initializeGL()
{
    glewInit();

    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);

    solver_ = new SolverEuler();
    particles_system_ = new ParticlesSystem(solver_, 100);

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

    camera_.compute_view_projection();

    particles_system_->paintGL(dt, camera_);

    time_last_ = time_now;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
