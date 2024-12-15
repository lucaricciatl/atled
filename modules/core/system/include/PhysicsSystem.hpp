#ifndef PHYSICSSYSTEM_HPP
#define PHYSICSSYSTEM_HPP

#include "Component.hpp"
#include "EventBus.hpp"
#include "System.hpp"
#include <memory>
#include <vector>
#include <Entity.hpp>
#include "PhysicsManager.hpp"

class PhysicsSystem : public System {
public:
  PhysicsSystem(physics::PhysicsManager* physicsManager);

  void Update(float deltaTime) override;
  void Init();
  
private:
  physics::PhysicsManager* mPhysicsManager;
  std::vector<std::weak_ptr<Entity>> entitiesWithPhysics;
};

#endif // RENDERSYSTEM_HPP
