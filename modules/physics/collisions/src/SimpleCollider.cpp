#include "SimpleCollider.hpp"
namespace physics {

SimpleCollider::SimpleCollider(const math::BoundingBox& worldBounds, int maxDepth, int maxObjects)
    : octree(worldBounds, maxDepth, maxObjects) {}

void SimpleCollider::AddBody(Body* body) {
    if (body) {
        bodies.push_back(body);
        octree.Insert(body, body->GetBoundingBox());
    }
}
void SimpleCollider::DetectCollisions() {
    // Example of collision detection logic
    for (const auto& body : bodies) {
        std::vector<Body*> potentialCollisions;
        Retrieve(potentialCollisions, body->GetBoundingBox());

        for (Body* other : potentialCollisions) {
            if (body != other && body->GetBoundingBox().Intersects(other->GetBoundingBox())) {
                // Handle collision
            }
        }
    }
}

void SimpleCollider::Retrieve(std::vector<Body*>& results, const math::BoundingBox& queryBounds) const {
    octree.Retrieve(results, queryBounds);
}

} // namespace physics
