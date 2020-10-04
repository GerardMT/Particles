#ifndef COLLIDER_H
#define COLLIDER_H

#include "particle.h"

class Collider
{
public:
    virtual ~Collider() {};

    virtual void collide(Particle &p) const = 0;
};

#endif // COLLIDER_H
