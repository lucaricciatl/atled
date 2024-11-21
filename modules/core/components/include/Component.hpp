#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"

class Component {
public:
  Entity *owner;

  Component(Entity *owner) : owner(owner) {}
  virtual ~Component() = default;

  virtual void OnStart() {}
  virtual void OnUpdate(float deltaTime) {}
  virtual void OnDraw() {}
};

#endif // COMPONENT_HPP
