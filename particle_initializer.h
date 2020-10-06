#ifndef PARTICLEINITIALIZER_H
#define PARTICLEINITIALIZER_H

#include "particle.h"

class ParticleInitializer
{
public:
    virtual ~ParticleInitializer() {};

    virtual void initialize(Particle &p) = 0;
};

#endif // PARTICLEINITIALIZER_H
