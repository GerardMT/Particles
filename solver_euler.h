#ifndef SOLVEREULER_H
#define SOLVEREULER_H

#include "solver.h"

class SolverEuler : public Solver
{
public:
    void solve(float dt, vector<Particle> &particles) override;
};

#endif // SOLVEREULER_H
