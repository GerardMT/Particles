#include "forcegravity.h"

void ForceGravity::apply(vector<Particle> &particles) const
{
    for (auto par : particles) {
        par.force_ += GRAVITY_ * par.mass_;
    }
}
