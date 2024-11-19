

void ServiceProvider::Provide(std::shared_ptr<input::InputManager> inputMgr) {
  inputManager = inputMgr;
}

// Similarly for the other managers

std::shared_ptr<input::InputManager> ServiceProvider::GetInputManager() const {
  return inputManager;
}
