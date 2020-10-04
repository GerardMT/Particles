#include "particle_initializer.h"

void ParticleInitializer::initialize(Particle &p)
{
    if (p.life_time_ < 0.0) {
        this->initializeSpecialization(p);
    }
}
