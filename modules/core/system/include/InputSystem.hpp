#ifndef INPUTSYSTEM_HPP
#define INPUTSYSTEM_HPP

#include "EventBus.hpp"
#include "InputManager.hpp"
#include "System.hpp"

class InputSystem : public System {
public:
  InputSystem(input::InputManager *inputMgr, EventBus *eventBus);

  void Update(float deltaTime) override;

private:
  input::InputManager *inputManager;
  EventBus *eventBus;
};

#endif // INPUTSYSTEM_HPP
