#ifndef SOLVERIMPLICITEULER_H
#define SOLVERIMPLICITEULER_H

#import "solver.h"

using namespace std;

class SolverImplicitEuler : public Solver
{
public:
    void solve(float dt, vector<Particle> particles) override;
};

#endif // SOLVERIMPLICITEULER_H
