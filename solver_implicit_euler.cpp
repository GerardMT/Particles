#include "solver_implicit_euler.h"

void SolverImplicitEuler::solve(float dt, Particle &p) const
{
    p.vel_ = p.vel_ + dt * p.force_ / p.mass_;
    p.pos_ = p.pos_ + dt * p.vel_;
}
