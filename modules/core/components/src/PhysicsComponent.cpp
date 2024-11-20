#include "PhysicsComponent.hpp"
#include "Entity.hpp"

PhysicsComponent::PhysicsComponent(Entity *owner) : Component(owner) {
  // Inizializzazione del corpo fisico
}

void PhysicsComponent::OnStart() {
  // Codice di inizializzazione
}

void PhysicsComponent::OnUpdate(float deltaTime) {}
