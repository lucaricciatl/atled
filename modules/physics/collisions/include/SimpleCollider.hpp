#pragma once

#include <vector>
#include "Body.hpp"
#include "Octree.hpp"
#include "BoundingBox.hpp"

namespace physics {

class SimpleCollider {
public:
    // Constructor and Destructor
    SimpleCollider(const math::BoundingBox& worldBounds, int maxDepth = 5, int maxObjects = 10);
    ~SimpleCollider() = default;

    // Add a body to the collider
    void AddBody(Body* body);
    void Retrieve(std::vector<Body*>& results, const math::BoundingBox& queryBounds) const;

    // Perform collision detection
    void DetectCollisions();

private:
    math::Octree<Body*> octree;  // Octree for spatial partitioning
    std::vector<Body*> bodies;  // List of bodies (for management)
};

} // namespace physics
