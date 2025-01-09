#ifndef FRAMECONTROLLER_HPP
#define FRAMECONTROLLER_HPP

#include <memory>

#include "ControllerComponent.hpp"

class FrameController : public ControllerComponent {
   public:
    FrameController(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider)
        : ControllerComponent(owner, serviceProvider){};

    void OnAction(Action action, bool activated){};
    void Update(float deltaTime){};

   private:
    float speed;
};

#endif  // FRAMECONTROLLER_HPP
