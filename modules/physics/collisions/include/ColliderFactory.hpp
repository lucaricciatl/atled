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
    static void RegisterCollider(ColliderType colliderType, ImplementationType implType, ColliderCreator creator);

    // Sets the default implementation to use for a specific collider type
    static void SetDefaultImplementation(ColliderType colliderType, ImplementationType implType);

    // Creates a collider based on the type and the current default implementation
    static std::shared_ptr<ICollider> CreateCollider(ColliderType colliderType);

    // Creates a collider based on the type and implementation
    static std::shared_ptr<ICollider> CreateCollider(ColliderType colliderType, ImplementationType implType);

private:
    // Key generator for type and implementation mapping
    static std::string GetKey(ColliderType colliderType, ImplementationType implType);

    // Map to store registered collider creators
    static inline std::unordered_map<std::string, ColliderCreator> creators;

    // Map to store default implementation for each collider type
    static inline std::unordered_map<ColliderType, ImplementationType> defaultImplementations;
};

#endif // COLLIDER_FACTORY_H
