#ifndef SERVICE_PROVIDER_HPP
#define SERVICE_PROVIDER_HPP

#include <CameraManager.hpp>
#include <IGraphicManager.hpp>
#include <InputManager.hpp>
#include <memory>

#include "PhysicsManager.hpp"
#include "ResourceManager.hpp"

class ServiceProvider {
   public:
    ServiceProvider();   // Constructor declaration
    ~ServiceProvider();  // Destructor declaration

    // Provide shared pointers to the service provider
    void Provide(std::shared_ptr<input::InputManager> inputMgr);
    void Provide(std::shared_ptr<graphics::IGraphicManager> graphicsMgr);
    void Provide(std::shared_ptr<graphics::CameraManager> cameraMgr);
    void Provide(std::shared_ptr<resources::ResourceManager> resourceMgr);
    void Provide(std::shared_ptr<physics::PhysicsManager> physicsManager);

    // Getters for shared pointers
    std::shared_ptr<input::InputManager> GetInputManager() const;
    std::shared_ptr<graphics::IGraphicManager> GetGraphicManager() const;
    std::shared_ptr<graphics::CameraManager> GetCameraManager() const;
    std::shared_ptr<resources::ResourceManager> GetResourceManager() const;
    std::shared_ptr<physics::PhysicsManager> GetPhysicsManager() const;

   private:
    std::shared_ptr<input::InputManager> inputManager;
    std::shared_ptr<graphics::IGraphicManager> graphicsManager;
    std::shared_ptr<graphics::CameraManager> cameraManager;
    std::shared_ptr<resources::ResourceManager> resourceManager;
    std::shared_ptr<physics::PhysicsManager> physicsManager;
};

#endif  // SERVICE_PROVIDER_HPP
