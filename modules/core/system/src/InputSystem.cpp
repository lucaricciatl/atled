#include "InputSystem.hpp"
#include "InputEvent.hpp"

InputSystem::InputSystem(input::InputManager *inputMgr, EventBus *eventBus)
    : inputManager(inputMgr), eventBus(eventBus) {}

void InputSystem::Update(float deltaTime) {
  inputManager->Update();

  // Esempio di gestione degli input
  if (inputManager->IsKeyPressed("Space")) {
    InputEvent event("Space", true);
    eventBus->Publish(event);
  }
}
