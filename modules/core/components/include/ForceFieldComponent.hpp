// ForceFieldComponent.hpp
#ifndef FORCE_FIELD_COMPONENT_HPP
#define FORCE_FIELD_COMPONENT_HPP

#include "Component.hpp"
#include "FrameComponent.hpp"
#include <vector>
#include <memory>
#include "Vector3.hpp"

// Enum for different force field types
enum class ForceFieldType {
    None,
    Radial,
    Directional,
    Wind,
    Tangent
};

class ForceFieldComponent : public Component {
private:
    ForceFieldType mForceFieldType;                 // Type of force field
    float mStrength;                               // Strength of the force field
    float mRadius;                                 // Effective radius of the force field
    math::Vector3 mForceDirection;                 // Direction for directional and wind forces
    std::vector<Entity*> mAffectedEntities;        // Entities affected by the field

public:
    ForceFieldComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~ForceFieldComponent();

    // Setters
    void SetForceFieldType(ForceFieldType type);
    void SetStrength(float strength);
    void SetRadius(float radius);
    void SetForceDirection(const math::Vector3& direction);

    // Add/Remove entities
    void AddEntitiesFromList(const std::vector<Entity*>& entities);
    void AddAffectedEntity(Entity* entity);
    void RemoveAffectedEntity(Entity* entity);

    // Update the force field
    void Update(double deltaTime) override;
};

#endif // FORCE_FIELD_COMPONENT_HPP
