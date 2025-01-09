#ifndef PHYSICSSYSTEM_HPP
#define PHYSICSSYSTEM_HPP

#include <Entity.hpp>
#include <memory>
#include <vector>

#include "Component.hpp"
#include "EventBus.hpp"
#include "PhysicsManager.hpp"
#include "System.hpp"

class PhysicsSystem : public System {
   public:
    PhysicsSystem(physics::PhysicsManager* physicsManager);

    void Update(float deltaTime) override;
    void Init();

   private:
    physics::PhysicsManager* mPhysicsManager;
    std::vector<std::weak_ptr<Entity>> entitiesWithPhysics;
};

#endif  // RENDERSYSTEM_HPP
