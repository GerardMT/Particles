#include "particle_initializer_fountain.h"

#include <math.h>

ParticleInitializerFountain::ParticleInitializerFountain(glm::vec3 pos, float speed, float spread)
{
    pos_ = pos;
    speed_ = speed;
    spread_ = spread;
}

void ParticleInitializerFountain::initialize(Particle &p)
{
    p.pos_ = pos_;
    p.pos_pre_ = pos_;

    float i = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (M_PI / 2.0 * spread_)));
    float a = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (2.0 * M_PI)));

    p.vel_.x = speed_ * sin(i) * cos(a);
    p.vel_.z = speed_ * sin(i) * sin(a);
    p.vel_.y = speed_ * cos(i);

    const float mass_l = 0.1;
    const float mass_h = 0.5;

    p.mass_ = mass_l + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (mass_h - mass_l)));
}
