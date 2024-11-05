// CoreEngine.hpp
#pragma once

#include <memory>
#include "InputManager.hpp"
#include "IGraphicManager.hpp"

namespace engine {

class CoreEngine {
public:
    CoreEngine(std::unique_ptr<input::InputManager> inputMgr, std::unique_ptr<graphics::IGraphicManager> graphicsMgr);
    ~CoreEngine();

    // Initialize the engine components
    void Initialize();

    // Run the main loop
    void Run();

    // Shutdown the engine components
    void Shutdown();

private:
    std::unique_ptr<input::InputManager> inputManager;
    std::unique_ptr<graphics::IGraphicManager> graphicsManager;

    bool isRunning;

    // Main loop function
    void MainLoop();
};

} // namespace engine
