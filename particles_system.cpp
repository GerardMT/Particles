#include "particles_system.h"

#include <iostream>

#include "util.h"

using namespace std;

const float quad_vertices[] = {
  -1.0f,  1.0f, 0.0f,
  -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   1.0f,  1.0f, 0.0f,
  -1.0f,  1.0f, 0.0f
};

ParticlesSystem::ParticlesSystem(Solver *solver, unsigned int n)
{
    solver_ = solver;
    particles_.resize(n);
}

void ParticlesSystem::initialieGL()
{
    string particle_vert_str;
    readFile("./shader/particle.vert", particle_vert_str);
    particles_program_.addShaderFromSourceCode(QOpenGLShader::Vertex, particle_vert_str.c_str());
    cout << particles_program_.log().toUtf8().constData() << endl;

    string particle_frag_str;
    readFile("./shader/particle.frag", particle_frag_str);
    particles_program_.addShaderFromSourceCode(QOpenGLShader::Fragment, particle_frag_str.c_str());
    cout << particles_program_.log().toUtf8().constData() << endl;

    particles_program_.link();

    glGenVertexArrays(1, &particles_vao_);

    glGenBuffers(1, &particles_vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, particles_vbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices), &quad_vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glGenBuffers(1, &particles_tbo_);
    glBindBuffer(GL_ARRAY_BUFFER, particles_tbo_);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3) * particles_.size(), (void *) 0);
    glVertexAttribDivisor(1, 1);
}

void ParticlesSystem::paintGL(float dt, const Camera &camera)
{
    for (auto par : particles_) {
        par.force_ = glm::vec3(0.0);
    }

    for (auto f : force_fields_) {
        f->apply(particles_);
    }

    for (auto c : collliders_) {
        c->collide(particles_);
    }

    solver_->solve(dt, particles_);

    particles_program_.bind();
    glUniformMatrix4fv(particles_program_.uniformLocation("view_projection"), 1, GL_FALSE, glm::value_ptr(camera.view_projection));

    vector<glm::vec3> particlesPos;
    particlesPos.resize(particles_.size());
    for (unsigned int i = 0; i < particles_.size(); ++i) {
        particlesPos[i] = particles_[i].pos_;
    }

    glBindVertexArray(particles_vao_);
    glBindBuffer(GL_ARRAY_BUFFER, particles_tbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * particlesPos.size(), &particlesPos[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, particles_.size());
    glBindVertexArray(0);
}
