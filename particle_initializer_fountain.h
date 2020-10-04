#ifndef PARTICLEINITIALIZERFOUNTAIN_H
#define PARTICLEINITIALIZERFOUNTAIN_H

#include "particle_initializer.h"

class ParticleInitializerFountain : public ParticleInitializer
{
public:
    ParticleInitializerFountain(glm::vec3 pos);

private:
    void initializeSpecialization(Particle &p) override;

    glm::vec3 pos_;
};

#endif // PARTICLEINITIALIZERFOUNTAIN_H
