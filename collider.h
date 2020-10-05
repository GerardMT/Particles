#ifndef COLLIDER_H
#define COLLIDER_H

#include "particle.h"

class Collider
{
public:
    virtual ~Collider() {};

    virtual bool collide(Particle &p) const = 0;

    virtual void correct(Particle &p) const = 0;
};

#endif // COLLIDER_H
