#include "PhysicsSystem.hpp"

PhysicsSystem::PhysicsSystem(EventBus *eventBus) : eventBus(eventBus) {
  // Potresti popolare le liste dei componenti qui o utilizzare un sistema di
  // registri
}

void PhysicsSystem::Update(float deltaTime) {
  for (auto it = entitiesWithPhysics.begin();
       it != entitiesWithPhysics.end();) {
    if (auto entity = it->lock()) {
      auto physicsComp = entity->GetComponent<PhysicsComponent>();
      auto transformComp = entity->GetComponent<TransformComponent>();
      if (physicsComp && transformComp) {
        // Update physics
        transformComp->position += physicsComp->velocity * deltaTime;
      }
      ++it;
    } else {
      // Entity no longer exists, remove from the list
      it = entitiesWithPhysics.erase(it);
    }
  }
}
