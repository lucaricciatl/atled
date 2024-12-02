#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"


class Entity; // Forward declaration of Entity

class Component {
public:
    Entity* owner;

    Component(Entity* owner = nullptr) : owner(owner) {}

    virtual ~Component() = default;

    // Update method for the component
    virtual void Update(double deltatime) {};

    // Init method for the component
    virtual void Init() {};
};

#endif // COMPONENT_HPP