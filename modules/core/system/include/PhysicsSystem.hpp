#ifndef PHYSICSSYSTEM_HPP
#define PHYSICSSYSTEM_HPP

#include "Components.hpp"
#include "EventBus.hpp"
#include "System.hpp"
#include <memory>
#include <vector>

class PhysicsSystem : public System {
public:
  PhysicsSystem(EventBus *eventBus);

  void Update(float deltaTime) override;

private:
  EventBus *eventBus;
  // Use weak_ptr to prevent shared ownership that could lead to cyclic
  // references
  std::vector<std::weak_ptr<Entity>> entitiesWithPhysics;
};
