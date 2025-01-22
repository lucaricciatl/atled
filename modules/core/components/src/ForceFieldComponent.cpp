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

// RadialFieldComponent implementation
RadialFieldComponent::RadialFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
    : ForceFieldComponent(aOwner, serviceProvider) {}

RadialFieldComponent::~RadialFieldComponent() {}

void RadialFieldComponent::SetRadius(float radius) { mRadius = radius; }

void RadialFieldComponent::SetCenter(math::Vector3 center) { mCenter = center; }

void RadialFieldComponent::SetFallOffRadius(float aRadius) { mFallOffRadius = aRadius; }

void RadialFieldComponent::Update(double deltaTime) {
    for (Entity* entity : mAffectedEntities) {
        if (entity == nullptr) continue;

        auto frame = entity->GetComponent<FrameComponent>();
        if (frame == nullptr) continue;

        auto entityPosition = frame->GetPosition();
        auto fieldCenter = mOwner->GetComponent<FrameComponent>()->GetPosition();

        auto direction = entityPosition->GetVector3() - fieldCenter->GetVector3();
        float distance = direction.Magnitude();

        if (distance <= mRadius) {
            direction.Normalized();
            float forceMagnitude = mStrength / (distance * distance);
            math::Vector3 force = direction * forceMagnitude;
            math::Vector3 displacement = force * static_cast<float>(deltaTime);
            frame->SetPosition(frame->GetPosition()->GetVector3() + displacement);
        }
    }
}

// TangentFieldComponent implementation
TangentFieldComponent::TangentFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
    : ForceFieldComponent(aOwner, serviceProvider) {}

TangentFieldComponent::~TangentFieldComponent() {}

void TangentFieldComponent::SetRadius(float radius) { mRadius = radius; }

void TangentFieldComponent::SetCenter(math::Vector3 center) { mCenter = center; }

void TangentFieldComponent::SetAxis(math::Vector3 axis) { mAxis = axis; }

void TangentFieldComponent::Update(double deltaTime) {
    for (Entity* entity : mAffectedEntities) {
        if (entity == nullptr) continue;

        auto frame = entity->GetComponent<FrameComponent>();
        if (frame == nullptr) continue;

        auto entityPosition = frame->GetPosition();
        auto fieldCenter = mOwner->GetComponent<FrameComponent>()->GetPosition();

        auto direction = entityPosition->GetVector3() - fieldCenter->GetVector3();
        float distance = direction.Magnitude();

        if (distance <= mRadius) {
            auto tangentForce = mAxis.Cross(direction).Normalized() * (mStrength / distance);
            math::Vector3 displacement = tangentForce * static_cast<float>(deltaTime);
            frame->SetPosition(frame->GetPosition()->GetVector3() + displacement);
        }
    }
}

// GravitationalFieldComponent implementation
GravitationalFieldComponent::GravitationalFieldComponent(Entity* aOwner,
                                                         std::shared_ptr<ServiceProvider> serviceProvider)
    : ForceFieldComponent(aOwner, serviceProvider) {}

GravitationalFieldComponent::~GravitationalFieldComponent() {}

void GravitationalFieldComponent::SetRadius(float radius) { mRadius = radius; }

void GravitationalFieldComponent::SetCenter(math::Vector3 center) { mCenter = center; }

void GravitationalFieldComponent::SetFallOffRadius(float aRadius) { mFallOffRadius = aRadius; }

void GravitationalFieldComponent::Update(double deltaTime) {
    for (Entity* entity : mAffectedEntities) {
        if (entity == nullptr) continue;

        auto frame = entity->GetComponent<FrameComponent>();
        if (frame == nullptr) continue;

        auto entityPosition = frame->GetPosition();
        auto fieldCenter = mOwner->GetComponent<FrameComponent>()->GetPosition();

        auto direction = fieldCenter->GetVector3() - entityPosition->GetVector3();
        float distance = direction.Magnitude();

        if (distance <= mRadius) {
            direction.Normalized();
            float forceMagnitude = mStrength * (1 - (distance / mFallOffRadius));
            math::Vector3 force = direction * forceMagnitude;
            math::Vector3 displacement = force * static_cast<float>(deltaTime);
            frame->SetPosition(frame->GetPosition()->GetVector3() + displacement);
        }
    }
}

// DirectionalFieldComponent implementation
DirectionalFieldComponent::DirectionalFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
    : ForceFieldComponent(aOwner, serviceProvider) {}

DirectionalFieldComponent::~DirectionalFieldComponent() {}

void DirectionalFieldComponent::SetDirection(math::Vector3 direction) { mDirection = direction; }

void DirectionalFieldComponent::Update(double deltaTime) {
    for (Entity* entity : mAffectedEntities) {
        if (entity == nullptr) continue;

        auto frame = entity->GetComponent<FrameComponent>();
        if (frame == nullptr) continue;

        math::Vector3 displacement = mDirection * mStrength * static_cast<float>(deltaTime);
        frame->SetPosition(frame->GetPosition()->GetVector3() + displacement);
    }
}

// WindFieldComponent implementation
WindFieldComponent::WindFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
    : ForceFieldComponent(aOwner, serviceProvider) {}

WindFieldComponent::~WindFieldComponent() {}

void WindFieldComponent::SetDirection(math::Vector3 direction) { mDirection = direction; }

void WindFieldComponent::SetFrequency(float frequency) { mFrequency = frequency; }

void WindFieldComponent::SetVariance(float variance) { mVariance = variance; }

void WindFieldComponent::Update(double deltaTime) {
    for (Entity* entity : mAffectedEntities) {
        if (entity == nullptr) continue;

        auto frame = entity->GetComponent<FrameComponent>();
        if (frame == nullptr) continue;

        float windStrength = mStrength + (std::sin(mFrequency * deltaTime) * mVariance);
        math::Vector3 displacement = mDirection * windStrength * static_cast<float>(deltaTime);
        frame->SetPosition(frame->GetPosition()->GetVector3() + displacement);
    }
}

// RandomFieldComponent implementation
RandomFieldComponent::RandomFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
    : ForceFieldComponent(aOwner, serviceProvider) {}

RandomFieldComponent::~RandomFieldComponent() {}

void RandomFieldComponent::SetFrequency(float frequency) { mFrequency = frequency; }

void RandomFieldComponent::SetVariance(float variance) { mVariance = variance; }

void RandomFieldComponent::Update(double deltaTime) {
    for (Entity* entity : mAffectedEntities) {
        if (entity == nullptr) continue;

        auto frame = entity->GetComponent<FrameComponent>();
        if (frame == nullptr) continue;

        math::Vector3 randomForce(((std::rand() / static_cast<float>(RAND_MAX)) - 0.5f) * 2.0f * mVariance,
                                  ((std::rand() / static_cast<float>(RAND_MAX)) - 0.5f) * 2.0f * mVariance,
                                  ((std::rand() / static_cast<float>(RAND_MAX)) - 0.5f) * 2.0f * mVariance);

        math::Vector3 displacement = randomForce * static_cast<float>(deltaTime);
        frame->SetPosition(frame->GetPosition()->GetVector3() + displacement);
    }
}
