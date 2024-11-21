#include "Object.hpp"

Object::Object(int id) : id(id) {}

void Object::AddComponent(std::shared_ptr<Component> component) {
  component->owner = this;
  components.push_back(component);
}

void Object::OnStart() {
  for (auto &component : components) {
    component->OnStart();
  }
}

void Object::OnUpdate(float deltaTime) {
  for (auto &component : components) {
    component->OnUpdate(deltaTime);
  }
}

void Object::OnDraw() {
  for (auto &component : components) {
    component->OnDraw();
  }
}
