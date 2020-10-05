#ifndef COLLIDERPOLYGON_H
#define COLLIDERPOLYGON_H

#include "collider.h"
#include "collider_plane.h"

#include <vector>

using namespace std;

class ColliderPolygon : public Collider
{
public:
    ColliderPolygon(const vector<glm::vec3> &points, float bouncing, float friction);

    bool collide(Particle &p) const override;

    void correct(Particle &p) const override;

private:
    ColliderPlane collider_plane_;

    vector<glm::vec3> points_;

    float bouncing_;
    float friction_;
};

#endif // COLLIDERPOLYGON_H
