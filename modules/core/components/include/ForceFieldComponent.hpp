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
    RadialFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~RadialFieldComponent();

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
    TangentFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~TangentFieldComponent();

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
    GravitationalFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~GravitationalFieldComponent();

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
    DirectionalFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~DirectionalFieldComponent();

    void SetDirection(math::Vector3 direction);

    void Update(double deltaTime) override;

    math::Vector3 mDirection;
};

class WindFieldComponent : public ForceFieldComponent {
   public:
    WindFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~WindFieldComponent();

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
    RandomFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~RandomFieldComponent();

    void SetFrequency(float frequency);
    void SetVariance(float variance);

    void Update(double deltaTime) override;

    float mFrequency;
    float mVariance;
};

#endif // FORCE_FIELD_COMPONENT_HPP
