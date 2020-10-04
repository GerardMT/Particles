#ifndef GLWIDGET_H_
#define GLWIDGET_H_

#include "camera.h"
#include "object.h"
#include "particle_system.h"
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

    vector<Object *> objects_;

    Solver *solver_euler_;
    Solver *solver_implicit_euler_;

    ParticleInitializer *particle_initializer_fountain_;
    ParticleInitializer *particle_initializer_waterfall_;

    ParticleSystem *particles_system_;

    vector<PaintGL*> paint_gl_;

    chrono::steady_clock::time_point  time_last_;

    const glm::vec3 GRAVITY_ = glm::vec3(0.0, -9.8, 0.0);

private slots:
    void uiSolverEuler(bool v);

    void uiSolverImplicitEuler(bool v);

    void uiParticleInitializerFountain(bool v);

    void uiParticleInitializerWatterfall(bool v);
};

#endif  //  GLWIDGET_H_
