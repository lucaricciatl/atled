#include "RigidBodyComponent.hpp"

#include <Action.hpp>

void RigidBodyComponent::OnAction(Action action, bool activated) {
    // Default implementation (can be empty or provide basic handling)
}

void RigidBodyComponent::Update(double deltaTime) {}

void RigidBodyComponent::SetCollidable(bool aCollidable) { rigidBody->SetCollidable(aCollidable); }
void RigidBodyComponent::SetStatic(bool aStatic) { rigidBody->SetStatic(aStatic); };

bool RigidBodyComponent::IsCollidable() { return rigidBody->IsCollidable(); };

bool RigidBodyComponent::IsStatic() { return rigidBody->IsStatic(); };

void RigidBodyComponent::SetUseGravity(bool aGravity) { rigidBody->SetUseGravity(aGravity); };
