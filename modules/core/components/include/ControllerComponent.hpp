#ifndef CONTROLLERCOMPONENT_HPP
#define CONTROLLERCOMPONENT_HPP

#include <Action.hpp>

#include "Component.hpp"

class ControllerComponent : public Component {
   public:
    ControllerComponent(Entity* aOwner, std::shared_ptr<ServiceProvider>) : Component(aOwner){};

    virtual void OnAction(Action aAction, bool aActivated);
    virtual void Update(float aDeltaTime);

   private:
};

#endif  // PLAYERCONTROLLER_HPP