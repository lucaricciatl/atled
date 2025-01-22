// ForceFieldComponent.cpp
#include "ForceFieldComponent.hpp"
#include <cmath>
#include <algorithm> // For std::remove

// Constructor
ForceFieldComponent::ForceFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
    : Component(aOwner), mStrength(1.0f) {}

// Destructor
ForceFieldComponent::~ForceFieldComponent() {}

// Set the strength of the force field
void ForceFieldComponent::SetStrength(float strength) {
    mStrength = strength;
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
    // Iterate through all affected entities
    for (Entity* entity : mAffectedEntities) {
        if (entity == nullptr) continue;

        // Get the entity's position
        auto frame = entity->GetComponent<FrameComponent>();
        if (frame == nullptr) continue;

        auto entityPosition = frame->GetPosition();
        auto fieldCenter = mOwner->GetComponent<FrameComponent>()->GetPosition();

        // Calculate the direction and distance
        auto direction = entityPosition->GetVector3() - fieldCenter->GetVector3();
        float distance = direction.Magnitude();

        // If the entity is within the radius of the force field

            direction.Normalized(); // Normalize the direction vector

            float forceMagnitude = mStrength / ( distance * distance ) ;

            // Apply the force to the entity
            math::Vector3 force = direction * forceMagnitude;

            // Add force to the entity (assuming an AddForce method exists in the entity or its physics component)lculated force
            math::Vector3 displacement = force * static_cast<float>(deltaTime); // Displacement = Force * deltaTime
            auto pos=frame->GetPosition();
            frame->SetPosition(pos->GetVector3() + displacement);
        
    }
}

void ForceFieldComponent::AddEntitiesFromList(const std::vector<Entity*>& entities) {
    for (Entity* entity : entities) {
        if (entity != nullptr) {
            AddAffectedEntity(entity);
        }
    }
}
