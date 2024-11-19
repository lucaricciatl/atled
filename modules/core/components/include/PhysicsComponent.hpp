#ifndef PHYSICSCOMPONENT_HPP
#define PHYSICSCOMPONENT_HPP

#include "Component.hpp"
#include "PhysicsBody.hpp" // Supponendo che tu abbia una classe PhysicsBody

class PhysicsComponent : public Component {
public:
    PhysicsBody physicsBody;

    PhysicsComponent(GameObject* owner);

    void OnStart() override;
    void OnUpdate(float deltaTime) override;
};

#endif // PHYSICSCOMPONENT_HPP
