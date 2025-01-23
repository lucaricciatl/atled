// ForceFieldComponent.hpp
#ifndef FORCE_FIELD_COMPONENT_HPP
#define FORCE_FIELD_COMPONENT_HPP

#include "Component.hpp"
#include "FrameComponent.hpp"
#include <vector>
#include <memory>
#include "Vector3.hpp"

class ForceFieldComponent : public Component {
public:
    ForceFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~ForceFieldComponent();

    void SetStrength(float strength);

    // Add/Remove entities
    void AddEntitiesFromList(const std::vector<Entity*>& entities);
    void AddAffectedEntity(Entity* entity);
    void RemoveAffectedEntity(Entity* entity);

    // Update the force field
    void Update(double deltaTime) override;

    float mStrength;                         // Strength of the force field
    math::Vector3 mForceDirection;           // Direction for directional and wind forces
    std::vector<Entity*> mAffectedEntities;  // Entities affected by the field
};
class RadialFieldComponent : public ForceFieldComponent {
   public:
    RadialFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
        : ForceFieldComponent(aOwner, serviceProvider), mRadius(0.0f), mCenter({0, 0, 0}), mFallOffRadius(0.0f) {}

    ~RadialFieldComponent() {}

    void SetRadius(float radius);
    void SetCenter(math::Vector3 center);
    void SetFallOffRadius(float aRadius);

    void Update(double deltaTime) override;

    float mRadius;
    math::Vector3 mCenter;
    float mFallOffRadius;
};

class TangentFieldComponent : public ForceFieldComponent {
   public:
    TangentFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
        : ForceFieldComponent(aOwner, serviceProvider), mRadius(0.0f), mCenter({0, 0, 0}), mAxis({0, 1, 0}) {}

    ~TangentFieldComponent() {}

    void SetRadius(float radius);
    void SetCenter(math::Vector3 center);
    void SetAxis(math::Vector3 axis);

    void Update(double deltaTime) override;

    float mRadius;
    math::Vector3 mCenter;
    math::Vector3 mAxis;
};

class GravitationalFieldComponent : public ForceFieldComponent {
   public:
    GravitationalFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
        : ForceFieldComponent(aOwner, serviceProvider), mRadius(0.0f), mCenter({0, 0, 0}), mFallOffRadius(1000.0f) {}

    ~GravitationalFieldComponent() {}

    void SetRadius(float radius);
    void SetCenter(math::Vector3 center);
    void SetFallOffRadius(float aRadius);

    void Update(double deltaTime) override;

    float mRadius;
    math::Vector3 mCenter;
    float mFallOffRadius;
};

class DirectionalFieldComponent : public ForceFieldComponent {
   public:
    DirectionalFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
        : ForceFieldComponent(aOwner, serviceProvider), mDirection({0, 0, 1}) {}

    ~DirectionalFieldComponent() {}

    void SetDirection(math::Vector3 direction);

    void Update(double deltaTime) override;

    math::Vector3 mDirection;
};

class WindFieldComponent : public ForceFieldComponent {
   public:
    WindFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
        : ForceFieldComponent(aOwner, serviceProvider), mDirection({0, 0, 1}), mFrequency(0.0f), mVariance(0.0f) {}

    ~WindFieldComponent() {}

    void SetDirection(math::Vector3 direction);
    void SetFrequency(float frequency);
    void SetVariance(float variance);

    void Update(double deltaTime) override;

    math::Vector3 mDirection;
    float mFrequency;
    float mVariance;
};

class RandomFieldComponent : public ForceFieldComponent {
   public:
    RandomFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
        : ForceFieldComponent(aOwner, serviceProvider), mFrequency(0.0f), mVariance(0.0f) {}

    ~RandomFieldComponent() {}

    void SetFrequency(float frequency);
    void SetVariance(float variance);

    void Update(double deltaTime) override;

    float mFrequency;
    float mVariance;
};

#endif