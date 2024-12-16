#pragma once

#include "ICollider.hpp"
#include "BoundingBox.hpp"
#include "Body.hpp"
#include <vector>

namespace physics {

class AdvancedCollider : public ICollider {
public:
    AdvancedCollider(const math::BoundingBox& worldBounds, int maxDepth = 5, int maxObjects = 10);
    ~AdvancedCollider() override = default;

    void AddBody(Body* body) override;
    void DetectCollisions() override;

private:
    std::vector<Body*> bodies;
    math::BoundingBox worldBounds;
};


} // namespace physics
