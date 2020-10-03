#ifndef PARTICLESSYSTEM_H
#define PARTICLESSYSTEM_H

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <QOpenGLShaderProgram>
#include <vector>

#include "camera.h"
#include "collider.h"
#include "force_field.h"
#include "particle.h"
#include "solver.h"

using namespace std;

class ParticlesSystem
{
public:
    ParticlesSystem(Solver *solver, unsigned int n);

    void add_force_field(const ForceField* f);

    void add_collider(const Collider *c);

    void initialieGL();

    void paintGL(float dt, const Camera &camera);

private:
    vector<Particle> particles_;

    const Solver *solver_;
    vector<const ForceField *> force_fields_;
    vector<const Collider *> collliders_;

    QOpenGLShaderProgram particles_program_;

    GLuint particles_vao_;
    GLuint particles_vbo_;
    GLuint particles_tbo_;
};

#endif // PARTICLESSYSTEM_H
