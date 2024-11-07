#pragma once

#include "IEngine.hpp"
#include "InputManager.hpp"            // Include the full definition of InputManager
#include "IGraphicManager.hpp"          // Include the full definition of IGraphicManager
#include <memory>

namespace engine {


    class CoreEngine : public IEngine {
    public:
        // Constructor with unique_ptr arguments
        CoreEngine(std::unique_ptr<input::InputManager> inputMgr,
            std::unique_ptr<graphics::IGraphicManager> graphicsMgr);
        ~CoreEngine() override = default;

        void Init() override;
        void Stop() override;
        void Start() override;
        void Shutdown() override;

    protected:
        void EngineLoop();

        std::unique_ptr<input::InputManager> inputManager;
        std::unique_ptr<graphics::IGraphicManager> graphicsManager;
        bool isRunning = false;
        bool isReady = false;
    };

} // namespace engine
