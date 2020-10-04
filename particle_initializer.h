#ifndef PARTICLEINITIALIZER_H
#define PARTICLEINITIALIZER_H

#include "particle.h"

class ParticleInitializer
{
public:
    virtual ~ParticleInitializer() {};

    void initialize(Particle &p);

private:
    virtual void initializeSpecialization(Particle &p) = 0;
};

#endif // PARTICLEINITIALIZER_H
