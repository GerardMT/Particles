#ifndef GLWIDGET_H_
#define GLWIDGET_H_

#include "camera.h"
#include "particles_system.h"
#include "solver.h"

#include <GL/glew.h>
#include <QGLWidget>
#include <QOpenGLShaderProgram>

using namespace std;

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = nullptr);

    ~GLWidget();

protected:
    void initializeGL() override;

    void resizeGL(int w, int h) override;

    void paintGL() override;

private:
    Camera camera_;

    Solver *solver_;
    ParticlesSystem particles_system_;

    chrono::steady_clock::time_point  time_last_;

    const glm::vec3 GRAVITY_ = glm::vec3(0.0, -9.8, 0.0);
};

#endif  //  GLWIDGET_H_
