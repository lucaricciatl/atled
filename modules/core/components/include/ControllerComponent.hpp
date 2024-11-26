#ifndef CONTROLLERCOMPONENT_HPP
#define CONTROLLERCOMPONENT_HPP

#include "Component.hpp"
#include <Action.hpp>

class ControllerComponent : public Component {
public:
    ControllerComponent(Entity* owner, std::shared_ptr<ServiceProvider>) : Component(owner){};

    virtual void OnAction(Action action, bool activated);
    virtual void Update(float deltaTime);

private:

};

#endif // PLAYERCONTROLLER_HPP