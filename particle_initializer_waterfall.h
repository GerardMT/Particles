#ifndef PARTICLEINITIALIZERWATERFALL_H
#define PARTICLEINITIALIZERWATERFALL_H

#include "particle_initializer.h"

class ParticleInitializerWaterfall : public ParticleInitializer
{
public:
    ParticleInitializerWaterfall(glm::vec3 pos, float speed, float spread);

    void initialize(Particle &p) override;

    glm::vec3 pos_;
    float speed_;
    float spread_;
};

#endif // PARTICLEINITIALIZERWATERFALL_H
