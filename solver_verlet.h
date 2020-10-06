#ifndef SOLVERVERLET_H
#define SOLVERVERLET_H

#include "solver.h"

class SolverVerlet : public Solver
{
public:
    void solve(float dt, Particle &p) const override;

private:
    const float k_ = 0.9f;
};

#endif // SOLVERVERLET_H
