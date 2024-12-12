#include "ColliderFactory.hpp"

// Registers a collider creator for a specific type and implementation
void ColliderFactory::RegisterCollider(ColliderType colliderType, ImplementationType implType, ColliderCreator creator) {
    auto key = GetKey(colliderType, implType);
    creators[key] = creator;

    // Set default implementation if not already set
    if (defaultImplementations.find(colliderType) == defaultImplementations.end()) {
        defaultImplementations[colliderType] = implType;
    }
}

// Sets the default implementation to use for a specific collider type
void ColliderFactory::SetDefaultImplementation(ColliderType colliderType, ImplementationType implType) {
    auto key = GetKey(colliderType, implType);
    if (creators.find(key) == creators.end()) {
        throw std::invalid_argument("Implementation not registered for this collider type.");
    }
    defaultImplementations[colliderType] = implType;
}

// Creates a collider based on the type and the current default implementation
std::shared_ptr<ICollider> ColliderFactory::CreateCollider(ColliderType colliderType) {
    if (defaultImplementations.find(colliderType) == defaultImplementations.end()) {
        throw std::invalid_argument("Default implementation not set for this collider type.");
    }
    return CreateCollider(colliderType, defaultImplementations[colliderType]);
}

// Creates a collider based on the type and implementation
std::shared_ptr<ICollider> ColliderFactory::CreateCollider(ColliderType colliderType, ImplementationType implType) {
    auto key = GetKey(colliderType, implType);
    if (creators.find(key) != creators.end()) {
        return creators[key]();
    }
    throw std::invalid_argument("Collider type or implementation not registered.");
}

// Key generator for type and implementation mapping
std::string ColliderFactory::GetKey(ColliderType colliderType, ImplementationType implType) {
    return std::to_string(static_cast<int>(colliderType)) + "_" + std::to_string(static_cast<int>(implType));
}
