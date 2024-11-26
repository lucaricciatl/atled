#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"
#include "ServiceProvider.hpp"

class Entity; // Forward declaration of Entity

class Component {
public:
  Entity *owner;

  Component(Entity* owner) : owner(owner) {}

  virtual ~Component() = default;

  virtual void Update(double deltatime) {};

};

#endif // COMPONENT_HPP
