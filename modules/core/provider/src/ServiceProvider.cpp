#include "ServiceProvider.hpp"

// Constructor
ServiceProvider::ServiceProvider() = default;

// Destructor
ServiceProvider::~ServiceProvider() = default;

// Provide methods
void ServiceProvider::Provide(std::shared_ptr<input::InputManager> inputMgr) { inputManager = std::move(inputMgr); }

void ServiceProvider::Provide(std::shared_ptr<graphics::IGraphicManager> graphicsMgr) {
    graphicsManager = std::move(graphicsMgr);
}

void ServiceProvider::Provide(std::shared_ptr<graphics::CameraManager> cameraMgr) {
    cameraManager = std::move(cameraMgr);
}

void ServiceProvider::Provide(std::shared_ptr<resources::ResourceManager> resourceMgr) {
    resourceManager = std::move(resourceMgr);
}

void ServiceProvider::Provide(std::shared_ptr<physics::PhysicsManager> aPhysicsManager) {
    physicsManager = std::move(aPhysicsManager);
}

// Getter methods
std::shared_ptr<input::InputManager> ServiceProvider::GetInputManager() const { return inputManager; }

std::shared_ptr<graphics::IGraphicManager> ServiceProvider::GetGraphicManager() const { return graphicsManager; }

std::shared_ptr<graphics::CameraManager> ServiceProvider::GetCameraManager() const { return cameraManager; }

std::shared_ptr<resources::ResourceManager> ServiceProvider::GetResourceManager() const { return resourceManager; }

std::shared_ptr<physics::PhysicsManager> ServiceProvider::GetPhysicsManager() const { return physicsManager; }