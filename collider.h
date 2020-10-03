#ifndef COLLIDER_H
#define COLLIDER_H

#include "particle.h"

#include <vector>

using namespace std;

class Collider
{
public:
    virtual void collide(vector<Particle> &particles) const = 0;
};

#endif // COLLIDER_H
