// ForceFieldComponent.hpp
#ifndef FORCE_FIELD_COMPONENT_HPP
#define FORCE_FIELD_COMPONENT_HPP

#include "Component.hpp"
#include "FrameComponent.hpp"
#include <vector>
#include <memory>
#include "Vector3.hpp"

class ForceFieldComponent : public Component {
private:
    float mStrength;                               // Strength of the force field
    math::Vector3 mForceDirection;                 // Direction for directional and wind forces
    std::vector<Entity*> mAffectedEntities;        // Entities affected by the field

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
};

class RadialFieldComponent : public ForceFieldComponent {
   public:
    RadialFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~RadialFieldComponent();

    void SetRadius(float radius);
    void SetCenter(math::Vector3 center);
    void SetFallOffRadius(float aRadius);

    void Update(double deltaTime) override;
};

class TangentFieldComponent : public ForceFieldComponent {
   public:
    TangentFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~TangentFieldComponent();

    void SetRadius(float radius);
    void SetCenter(math::Vector3 center);
    void SetAxis(math::Vector3 axis);

    void Update(double deltaTime) override;
};

class GravitationalFieldComponent : public ForceFieldComponent {
   public:
    GravitationalFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~GravitationalFieldComponent();

    void SetRadius(float radius);
    void SetCenter(math::Vector3 center);
    void SetFallOffRadius(float aRadius);

    void Update(double deltaTime) override;
};

class DirectionalFieldComponent : public ForceFieldComponent {
   public:
    DirectionalFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~DirectionalFieldComponent();

    void SetDirection(math::Vector3 direction);

    void Update(double deltaTime) override;
};

class WindFieldComponent : public ForceFieldComponent {
   public:
    WindFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~WindFieldComponent();

    void SetDirection(math::Vector3 direction);
    void SetFrequency(float frequency);
    void SetVariance(float variance);

    void Update(double deltaTime) override;
};

class RandomFieldComponent : public ForceFieldComponent {
   public:
    RandomFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~RandomFieldComponent();

    void SetFrequency(float frequency);
    void SetVariance(float variance);

    void Update(double deltaTime) override;
};

#endif // FORCE_FIELD_COMPONENT_HPP
