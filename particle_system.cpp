#include "particle_system.h"

#include <iostream>

#include "force_field_gravity.h"
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

ParticleSystem::ParticleSystem(Solver &s, ParticleInitializer &i, unsigned int n)
{
    solver_ = &s;
    particles_.resize(n);
    initializer_ = &i;
}

ParticleSystem::~ParticleSystem()
{
    for (auto f : force_fields_) {
        delete f;
    }
    for (auto c : collliders_) {
        delete c;
    }
}

void ParticleSystem::solver(Solver &s)
{
    solver_ = &s;
}

void ParticleSystem::particleInitializer(ParticleInitializer &i)
{
    initializer_ = &i;
}

void ParticleSystem::initialieGL()
{
    string vert_str;
    readFile("../shader/particle.vert", vert_str);
    program_.addShaderFromSourceCode(QOpenGLShader::Vertex, vert_str.c_str());
    cout << program_.log().toUtf8().constData() << endl;

    string frag_str;
    readFile("../shader/particle.frag", frag_str);
    program_.addShaderFromSourceCode(QOpenGLShader::Fragment, frag_str.c_str());
    cout << program_.log().toUtf8().constData() << endl;

    program_.link();

    glGenVertexArrays(1, &vao_);

    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices), &quad_vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glGenBuffers(1, &tbo_);
    glBindBuffer(GL_ARRAY_BUFFER, tbo_);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3) * particles_.size(), (void *) 0);
    glVertexAttribDivisor(1, 1);

    glGenBuffers(1, &cdbo_);
    glBindBuffer(GL_ARRAY_BUFFER, cdbo_);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3) * particles_.size(), (void *) 0);
    glVertexAttribDivisor(2, 1);

    force_fields_.push_back(new ForceFieldGravity());
}

void ParticleSystem::paintGL(float dt, const Camera &camera)
{
    for (auto p : particles_) {
        p.force_ = glm::vec3(0.0);

        initializer_->initialize(p);

        for (auto f : force_fields_) {
            f->apply(p);
        }

        for (auto c : collliders_) {
            c->collide(p);
        }

        solver_->solve(dt, p);

    }

    program_.bind();
    glUniformMatrix4fv(program_.uniformLocation("view_projection"), 1, GL_FALSE, glm::value_ptr(camera.view_projection));

    vector<glm::vec3> pos;
    pos.resize(particles_.size());

    vector<glm::vec3> camera_dir;
    camera_dir.resize(particles_.size());

    for (unsigned int i = 0; i < particles_.size(); ++i) {
        pos[i] = particles_[i].pos_;
        camera_dir[i] = glm::normalize(particles_[i].pos_ - camera.pos_);
    }

    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, tbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * pos.size(), &pos[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, cdbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * camera_dir.size(), &camera_dir[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, particles_.size());
    glBindVertexArray(0);
}
