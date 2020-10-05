#ifndef COLLIDERTRIANGLE_H
#define COLLIDERTRIANGLE_H

#include "collider_plane.h"

class ColliderTriangle : Collider
{
public:
    ColliderTriangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, float bouncing, float friction);

    bool collide(Particle &p) const override;

    void correct(Particle &p) const override;

private:
    ColliderPlane collider_plane_;

    glm::vec3 p1_;
    glm::vec3 p2_;
    glm::vec3 p3_;

    float area_;
};

#endif // COLLIDERTRIANGLE_H
