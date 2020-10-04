#ifndef PARTICLESSYSTEM_H
#define PARTICLESSYSTEM_H

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <QOpenGLShaderProgram>
#include <vector>

#include "collider.h"
#include "force_field.h"
#include "paint_gl.h"
#include "particle.h"
#include "particle_initializer.h"
#include "solver.h"

using namespace std;

class ParticleSystem : public PaintGL
{
public:
    ParticleSystem(Solver &s, ParticleInitializer &i, unsigned int n);

    ~ParticleSystem();

    void add_force_field(const ForceField* f);

    void add_collider(const Collider *c);

    void solver(Solver &s);

    void particleInitializer(ParticleInitializer &i);

    void initialieGL() override;

    void paintGL(float dt, const Camera &camera) override;

private:
    vector<Particle> particles_;

    const Solver *solver_;
    vector<const ForceField *> force_fields_;
    vector<const Collider *> collliders_;

    ParticleInitializer *initializer_;

    QOpenGLShaderProgram program_;

    GLuint vao_;
    GLuint vbo_;
    GLuint tbo_;
    GLuint cdbo_;
};

#endif // PARTICLESSYSTEM_H
