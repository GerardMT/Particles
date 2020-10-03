#include "solver_implicit_euler.h"

void SolverImplicitEuler::solve(float dt, vector<Particle> particles)
{
    for (auto par : particles) {
        par.vel_ = par.vel_ + dt * par.force_ / par.mass_;
        par.pos_ = par.pos_ + dt * par.vel_;
    }
}
