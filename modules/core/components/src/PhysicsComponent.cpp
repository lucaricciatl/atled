#include "PhysicsComponent.hpp"

PhysicsComponent::PhysicsComponent(GameObject* owner)
    : Component(owner), physicsBody() {
    // Inizializzazione del corpo fisico
}

void PhysicsComponent::OnStart() {
    // Codice di inizializzazione
}

void PhysicsComponent::OnUpdate(float deltaTime) {
    // Aggiornamento della fisica
    physicsBody.Update(deltaTime);
}
