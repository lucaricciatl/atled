#ifndef ICOLLIDER_H
#define ICOLLIDER_H

#include "ColliderType.hpp"
#include <memory>

class ICollider {
public:
    virtual ~ICollider() = default;

    // Gets the type of collider (e.g., Sphere, Box, Mesh)
    virtual ColliderType GetType() const = 0;

};

#endif // ICOLLIDER_H
