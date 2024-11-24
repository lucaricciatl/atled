#ifndef SERVICE_PROVIDER_HPP
#define SERVICE_PROVIDER_HPP

#include <memory>
#include <IGraphicManager.hpp>
#include <InputManager.hpp>
#include <CameraManager.hpp>
#include "ResourceManager.hpp"

class ServiceProvider {
public:
    // Provide shared pointers to the service provider
    void Provide(std::shared_ptr<input::InputManager> inputMgr);
    void Provide(std::shared_ptr<graphics::IGraphicManager> graphicsMgr);
    void Provide(std::shared_ptr<graphics::CameraManager> cameraMgr);
    void Provide(std::shared_ptr<resources::ResourceManager> resourceMgr);

    // Getters for shared pointers
    std::shared_ptr<input::InputManager> GetInputManager() const;
    std::shared_ptr<graphics::IGraphicManager> GetGraphicManager() const;
    std::shared_ptr<graphics::CameraManager> GetCameraManager() const;
    std::shared_ptr<resources::ResourceManager> GetResourceManager() const;

private:
    std::shared_ptr<input::InputManager> inputManager;
    std::shared_ptr<graphics::IGraphicManager> graphicsManager;
    std::shared_ptr<graphics::CameraManager> cameraManager;
    std::shared_ptr<resources::ResourceManager> resourceManager;
};

#endif // SERVICE_PROVIDER_HPP
