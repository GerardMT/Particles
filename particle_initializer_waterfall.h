#ifndef PARTICLEINITIALIZERWATERFALL_H
#define PARTICLEINITIALIZERWATERFALL_H

#include "particle_initializer.h"

class ParticleInitializerWaterfall : public ParticleInitializer
{
public:
    ParticleInitializerWaterfall(glm::vec3 pos);

private:
    void initializeSpecialization(Particle &p) override;

    glm::vec3 pos_;
};

#endif // PARTICLEINITIALIZERWATERFALL_H
