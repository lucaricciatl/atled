#include "PhysicsComponent.hpp"
#include "Object.hpp"

PhysicsComponent::PhysicsComponent(Object* owner)
    : Component(owner) {
    // Inizializzazione del corpo fisico
}

void PhysicsComponent::OnStart() {
    // Codice di inizializzazione
}

void PhysicsComponent::OnUpdate(float deltaTime) {
}
