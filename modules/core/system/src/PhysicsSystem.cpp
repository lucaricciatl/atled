#include "PhysicsSystem.hpp"
#include <PhysicsComponent.hpp>

PhysicsSystem::PhysicsSystem(EventBus *eventBus) : eventBus(eventBus) {
  // Potresti popolare le liste dei componenti qui o utilizzare un sistema di
  // registri
}

void PhysicsSystem::Update(float deltaTime) {
  
}
