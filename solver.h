#ifndef SOLVER_H
#define SOLVER_H

#include <vector>

#include "particle.h"

using namespace std;

class Solver
{
public:
    virtual void solve(float dt, vector<Particle> &particles) const = 0;

    virtual ~Solver() = 0;
};

#endif // SOLVER_H
