#include "solver_euler.h"

void SolverEuler::solve(float dt, vector<Particle> &particles) const
{
    for (auto par : particles) {
        par.pos_ = par.pos_ + dt * par.vel_;
        par.vel_ = par.vel_ + dt * par.force_ / par.mass_;
    }
}
