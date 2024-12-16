#pragma once

#include "ICollider.hpp"
#include <memory>
#include <vector>
#include "Body.hpp" 
#include "Octree.hpp" 

namespace physics{

class SimpleCollider : public ICollider {
public:
    // Constructor and Destructor
     SimpleCollider() : SimpleCollider(100.0f) {} // Default to a world size of 100 units

    SimpleCollider(float worldSize);
    ~SimpleCollider() = default;

    // Add a body to the collider for collision detection
    void AddBody(Body* body);

    // Perform collision detection
    void DetectCollisions();

private:
    // Octree for spatial partitioning
    //math::Octree<Body*> octree;

    // List of all bodies (for management purposes)
    std::vector<Body*> bodies;
};

}