#include "solver_verlet.h"

void SolverVerlet::solve(float dt, Particle &p) const
{
    //p.pos_pre_ = p.pos_ - dt * p.vel_;

    p.pos_ = p.pos_ + k_ * (p.pos_ - p.pos_pre_) + dt * dt / p.mass_ * p.force_;
    //p.vel_ = (p.pos_ - p.pos_pre_) / dt;
}
