#ifndef PARTICLEINITIALIZERFOUNTAIN_H
#define PARTICLEINITIALIZERFOUNTAIN_H

#include "particle_initializer.h"

class ParticleInitializerFountain : public ParticleInitializer
{
public:
    ParticleInitializerFountain(glm::vec3 pos, float speed, float spread);

    void initialize(Particle &p) override;

    glm::vec3 pos_;
    float speed_;
    float spread_;
};

#endif // PARTICLEINITIALIZERFOUNTAIN_H
