#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"

class Component {
public:
  Entity *owner;

  Component(Entity *owner) : owner(owner) {}
  virtual ~Component() = default;
};

#endif // COMPONENT_HPP
