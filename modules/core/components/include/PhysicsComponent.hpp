#ifndef PHYSICSCOMPONENT_HPP
#define PHYSICSCOMPONENT_HPP

#include "Component.hpp"

class PhysicsComponent : public Component {
public:
  PhysicsComponent(Entity *owner);

  void OnStart() override;
  void OnUpdate(float deltaTime) override;
};

#endif // PHYSICSCOMPONENT_HPP