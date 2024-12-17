#pragma once

#include <vector>
#include "Body.hpp"
#include "Octree.hpp"
#include "BoundingBox.hpp"

namespace physics {

    class SimpleCollider {
    public:
        SimpleCollider();

        void AddBody(Body* body);
        bool DetectCollisions(Body* a, Body* b);

    private:
        // Retrieves potential collision candidates for a given bounding box

        // Performs a more expensive and precise collision check
        bool PreciseCollisionCheck(Body* a, Body* b) const;

        // Member variables
        //math::Octree<Body*> octree;           // Assuming this is defined elsewhere
        std::vector<Body*> bodies;
    };


} // namespace physics
