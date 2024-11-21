#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"

class Entity; // Forward declaration of Entity

class Component {
public:
  Entity *owner;

  Component(Entity *owner) : owner(owner) {}
  virtual ~Component() = default;
};

#endif // COMPONENT_HPP
