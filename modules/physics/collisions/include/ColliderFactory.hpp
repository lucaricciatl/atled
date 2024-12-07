#ifndef COLLIDER_FACTORY_H
#define COLLIDER_FACTORY_H

#include "ICollider.hpp"
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <functional>
#include <string>

// Enum for Implementation Type
enum class ImplementationType {
    Default,
    Raylib,
    Custom
};

class ColliderFactory {
public:
    using ColliderCreator = std::function<std::shared_ptr<ICollider>()>;

    // Registers a collider creator for a specific type and implementation
    static void RegisterCollider(ColliderType colliderType, ImplementationType implType, ColliderCreator creator) {
        auto key = GetKey(colliderType, implType);
        creators[key] = creator;

        // Set default implementation if not already set
        if (defaultImplementations.find(colliderType) == defaultImplementations.end()) {
            defaultImplementations[colliderType] = implType;
        }
    }

    // Sets the default implementation to use for a specific collider type
    static void SetDefaultImplementation(ColliderType colliderType, ImplementationType implType) {
        auto key = GetKey(colliderType, implType);
        if (creators.find(key) == creators.end()) {
            throw std::invalid_argument("Implementation not registered for this collider type.");
        }
        defaultImplementations[colliderType] = implType;
    }

    // Creates a collider based on the type and the current default implementation
    static std::shared_ptr<ICollider> CreateCollider(ColliderType colliderType) {
        if (defaultImplementations.find(colliderType) == defaultImplementations.end()) {
            throw std::invalid_argument("Default implementation not set for this collider type.");
        }
        return CreateCollider(colliderType, defaultImplementations[colliderType]);
    }

    // Creates a collider based on the type and implementation
    static std::shared_ptr<ICollider> CreateCollider(ColliderType colliderType, ImplementationType implType) {
        auto key = GetKey(colliderType, implType);
        if (creators.find(key) != creators.end()) {
            return creators[key]();
        }
        throw std::invalid_argument("Collider type or implementation not registered.");
    }

private:
    // Key generator for type and implementation mapping
    static std::string GetKey(ColliderType colliderType, ImplementationType implType) {
        return std::to_string(static_cast<int>(colliderType)) + "_" + std::to_string(static_cast<int>(implType));
    }

    // Map to store registered collider creators
    static inline std::unordered_map<std::string, ColliderCreator> creators;

    // Map to store default implementation for each collider type
    static inline std::unordered_map<ColliderType, ImplementationType> defaultImplementations;
};


#endif // COLLIDER_FACTORY_H
