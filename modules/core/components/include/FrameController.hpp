#ifndef FRAMECONTROLLER_HPP
#define FRAMECONTROLLER_HPP

#include <memory>

#include "ControllerComponent.hpp"

class FrameController : public ControllerComponent {
   public:
    FrameController(Entity* aOwner, std::shared_ptr<ServiceProvider> aServiceProvider)
        : ControllerComponent(aOwner, aServiceProvider){};

    void OnAction(Action aAction, bool aActivated){};
    void Update(float aDeltaTime){};

   private:
    float speed;
};

#endif  // FRAMECONTROLLER_HPP
