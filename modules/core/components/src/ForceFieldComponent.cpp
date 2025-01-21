// ForceFieldComponent.cpp
#include "ForceFieldComponent.hpp"
#include <cmath>
#include <algorithm> // For std::remove

// Constructor
ForceFieldComponent::ForceFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
    : Component(aOwner), mForceFieldType(ForceFieldType::None), mStrength(0.0f), mRadius(10.0f), mForceDirection(0.0f, 0.0f, 0.0f) {}

// Destructor
ForceFieldComponent::~ForceFieldComponent() {}

// Set force field type
void ForceFieldComponent::SetForceFieldType(ForceFieldType type) {
    mForceFieldType = type;
}

// Set the strength of the force field
void ForceFieldComponent::SetStrength(float strength) {
    mStrength = strength;
}

// Set the radius of the force field
void ForceFieldComponent::SetRadius(float radius) {
    mRadius = radius;
}

// Set the force direction
void ForceFieldComponent::SetForceDirection(const math::Vector3& direction) {
    mForceDirection = direction;
    mForceDirection.Normalized();
}

// Add an entity to the affected list
void ForceFieldComponent::AddAffectedEntity(Entity* entity) {
    mAffectedEntities.push_back(entity);
}

// Remove an entity from the affected list
void ForceFieldComponent::RemoveAffectedEntity(Entity* entity) {
    mAffectedEntities.erase(
        std::remove(mAffectedEntities.begin(), mAffectedEntities.end(), entity),
        mAffectedEntities.end());
}

// Update the force field, applying forces to all affected entities
void ForceFieldComponent::Update(double deltaTime) {
    
}
