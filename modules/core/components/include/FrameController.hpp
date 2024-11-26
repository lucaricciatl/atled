#ifndef FRAMECONTROLLER_HPP
#define FRAMECONTROLLER_HPP

#include "ControllerComponent.hpp"
#include <memory>

class FrameController : public ControllerComponent {
public:
    FrameController(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider) : ControllerComponent(owner,serviceProvider) {};

    void OnAction(Action action, bool activated) {};
    void Update(float deltaTime) {};

private:
    float speed;
};

#endif // FRAMECONTROLLER_HPP
