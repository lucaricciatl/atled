#include "GameObject.hpp"

GameObject::GameObject(int id)
    : id(id) {}

void GameObject::AddComponent(std::shared_ptr<Component> component) {
    component->owner = this;
    components.push_back(component);
}

void GameObject::OnStart() {
    for (auto& component : components) {
        component->OnStart();
    }
}

void GameObject::OnUpdate(float deltaTime) {
    for (auto& component : components) {
        component->OnUpdate(deltaTime);
    }
}

void GameObject::OnDraw() {
    for (auto& component : components) {
        component->OnDraw();
    }
}
