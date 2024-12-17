#include <vector>
#include <set>
#include <algorithm>
#include <utility> // for std::minmax
#include "body.hpp"
#include "BoundingBox.hpp"
#include "Octree.hpp" // Assuming you have an octree implementation
#include <SimpleCollider.hpp>


namespace physics {


SimpleCollider::SimpleCollider()
{
    // Constructor body can be empty if initialization lists are sufficient
}

void SimpleCollider::AddBody(Body* body) {
    if (body) {
        bodies.push_back(body);
        //octree.Insert(body, body->GetBoundingBox());
    }
}

bool SimpleCollider::DetectCollisions(Body* a, Body* b) {
    // Ensure both bodies are valid
    if (!a || !b) {
        return false;
    }

    // First, do a bounding box intersection test
    if (a->GetBoundingBox().Intersects(b->GetBoundingBox())) {
        b->ApplyForce(math::Vector3(0, 20, 0));
        return true;
    }

    // No intersection found
    return false;
}


bool SimpleCollider::PreciseCollisionCheck(Body* a, Body* b) const {
    // Placeholder for a more advanced collision detection routine.
    // Could use OBB checks, GJK, SAT, or any other algorithm depending on your shapes.
    return true;
}
}