#ifndef FORCEFIELD_H
#define FORCEFIELD_H

#include "particle.h"

#include <vector>

using namespace std;

class ForceField
{
    virtual void apply(vector<Particle> &particles) const = 0;
};

#endif // FORCEFIELD_H
