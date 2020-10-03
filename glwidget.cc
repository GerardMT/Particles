
#include "glwidget.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
  setFocusPolicy(Qt::StrongFocus);
}

void GLWidget::initializeGL()
{
    glewInit();

    glEnable(GL_NORMALIZE);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::resizeGL(int w, int h)
{
//  width_ = w;
//  height_ = h;
}


void GLWidget::paintGL() {
    glClearColor(0.55f, 0.63f, 0.77f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
