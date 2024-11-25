#include "ServiceProvider.hpp"

void ServiceProvider::Provide(std::shared_ptr<input::InputManager> inputMgr) {
    inputManager = std::move(inputMgr);
}

void ServiceProvider::Provide(std::shared_ptr<graphics::IGraphicManager> graphicsMgr) {
    graphicsManager = std::move(graphicsMgr);
}

void ServiceProvider::Provide(std::shared_ptr<graphics::CameraManager> cameraMgr) {
    cameraManager = std::move(cameraMgr);
}

void ServiceProvider::Provide(std::shared_ptr<resources::ResourceManager> resourceMgr) {
    resourceManager = std::move(resourceMgr);
}

std::shared_ptr<input::InputManager> ServiceProvider::GetInputManager() const {
    return inputManager;
}

std::shared_ptr<graphics::IGraphicManager> ServiceProvider::GetGraphicManager() const {
    return graphicsManager;
}

std::shared_ptr<graphics::CameraManager> ServiceProvider::GetCameraManager() const {
    return cameraManager;
}

std::shared_ptr<resources::ResourceManager> ServiceProvider::GetResourceManager() const {
    return resourceManager;
}
