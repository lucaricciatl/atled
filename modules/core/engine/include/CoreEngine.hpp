#pragma once

#include <ResourceManager.hpp>
#include <functional>
#include <memory>
#include <vector>

#include "CameraManager.hpp"
#include "IEngine.hpp"
#include "IGraphicManager.hpp"  // Include the full definition of IGraphicManager
#include "InputManager.hpp"     // Include the full definition of InputManager
#include "PhysicsManager.hpp"

namespace engine {

class CoreEngine : public IEngine {
   public:
    // Constructor with unique_ptr arguments
    CoreEngine(std::unique_ptr<input::InputManager> inputMgr, std::unique_ptr<graphics::IGraphicManager> graphicsMgr,
               std::shared_ptr<graphics::CameraManager> cameraMgr, std::shared_ptr<resources::ResourceManager> resMgr,
               std::shared_ptr<physics::PhysicsManager> physicsManager);
    ~CoreEngine() override = default;

    void Stop() override;
    void Start() override;
    void Shutdown() override;

    // Register callback functions
    virtual void OnStart() = 0;
    virtual void OnRender() = 0;
    virtual void OnShutdown() = 0;
    virtual void OnUpdate() = 0;

   protected:
    void Init() override;
    void EngineLoop();

    std::unique_ptr<input::InputManager> inputManager;
    std::unique_ptr<graphics::IGraphicManager> graphicsManager;
    std::shared_ptr<graphics::CameraManager> cameraManager;

    bool isRunning = false;
    bool isReady = false;

   private:
    void pollInput();
    std::unique_ptr<std::thread> inputThread;  // Thread for input handling
};

}  // namespace engine
