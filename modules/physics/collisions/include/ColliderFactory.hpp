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

    // Factory method to create colliders
    static std::shared_ptr<ICollider> CreateCollider(ColliderType type) {
        switch (type) {
            case ColliderType::Simple:
                return std::make_shared<SimpleCollider>();
            case ColliderType::Advanced:
                return std::make_shared<AdvancedCollider>();
            default:
                throw std::invalid_argument("Unknown Collider Type");
        }
    }
};
}

#endif