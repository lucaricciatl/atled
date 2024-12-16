#ifndef COLLIDER_FACTORY_H
#define COLLIDER_FACTORY_H

#include "ICollider.hpp"
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <functional>
#include <string>
#include "SimpleCollider.hpp"
#include "AdvancedCollider.hpp"

namespace physics{

    enum class ColliderType {
        Simple,
        Advanced
    };

class ColliderFactory {
public:

    // Create a SimpleCollider
    static std::shared_ptr<SimpleCollider> CreateSimpleCollider() {
        math::BoundingBox worldBounds(
            math::Vector3(-1000.0f, -1000.0f, -1000.0f),
            math::Vector3(1000.0f, 1000.0f, 1000.0f)
        );
        return std::make_shared<SimpleCollider>(worldBounds);
    }

    // Create an AdvancedCollider
    static std::shared_ptr<AdvancedCollider> CreateAdvancedCollider() {
        math::BoundingBox worldBounds(
            math::Vector3(-1000.0f, -1000.0f, -1000.0f),
            math::Vector3(1000.0f, 1000.0f, 1000.0f)
        );
        return std::make_shared<AdvancedCollider>(worldBounds);
    }
};
}

#endif