#include "ServiceProvider.hpp"

void ServiceProvider::Provide(std::shared_ptr<input::InputManager> inputMgr) {
  inputManager = inputMgr;
}

void ServiceProvider::Provide(
    std::shared_ptr<graphics::IGraphicManager> graphicsMgr) {
  graphicsManager = graphicsMgr;
}

void ServiceProvider::Provide(
    std::shared_ptr<graphics::CameraManager> cameraMgr) {
  cameraManager = cameraMgr;
}

std::shared_ptr<input::InputManager> ServiceProvider::GetInputManager() const {
  return inputManager;
}

std::shared_ptr<graphics::IGraphicManager>
ServiceProvider::GetGraphicManager() const {
  return graphicsManager;
}

std::shared_ptr<graphics::CameraManager>
ServiceProvider::GetCameraManager() const {
  return cameraManager;
}
