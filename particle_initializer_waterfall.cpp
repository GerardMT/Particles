#include "particle_initializer_waterfall.h"

ParticleInitializerWaterfall::ParticleInitializerWaterfall(glm::vec3 pos)
{
    pos_ = pos;
}

void ParticleInitializerWaterfall::initializeSpecialization(Particle &p)
{
    p.pos_ = pos_;

    float i = M_PI / 2.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (M_PI / 2.0)));
    float a = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (2.0 * M_PI)));

    p.vel_.x = sin(i) * cos(a);
    p.vel_.x = sin(i) * sin(a);
    p.vel_.y = cos(i);
}
