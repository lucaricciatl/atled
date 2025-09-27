#ifndef ICOLLIDER_H
#define ICOLLIDER_H

#include "body.hpp"
#include <memory>

namespace physics {

class ICollider {
public:
    virtual ~ICollider() = default;

    // Add a body to the collider
    virtual void AddBody(Body* body) = 0;

    // Perform collision detection
    virtual void DetectCollisions() = 0;
};

} // namespace physics

#endif // ICOLLIDER_H
