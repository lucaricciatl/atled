#include "RigidBodyComponent.hpp"
#include <Action.hpp>

void RigidBodyComponent::OnAction(Action action, bool activated) {
    // Default implementation (can be empty or provide basic handling)
}

void RigidBodyComponent::Update(double deltaTime) {
    UpdatePhysics(deltaTime);
}
