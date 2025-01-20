#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"

class Entity;  // Forward declaration of Entity

class Component {
   public:
    Entity* mOwner;

    Component(Entity* aOwner = nullptr) : mOwner(aOwner) {}

    virtual ~Component() = default;

    // Update method for the component
    virtual void Update(double aDeltatime){};

    // Init method for the component
    virtual void Init(){};
};

#endif  // COMPONENT_HPP