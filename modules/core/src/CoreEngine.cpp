// CoreEngine.cpp
#include "CoreEngine.hpp"
#include <iostream>


namespace engine {


        CoreEngine::CoreEngine(std::unique_ptr<input::InputManager> inputMgr,
            std::unique_ptr<graphics::IGraphicManager> graphicsMgr)
            : inputManager(std::move(inputMgr)), graphicsManager(std::move(graphicsMgr)) {}

        void CoreEngine::Init() {
            graphicsManager->GetGraphicsContext()->InitWindowManager();
        }

        void CoreEngine::Start() {
            isRunning = true;
            OnStart();
            EngineLoop();
        }

        void CoreEngine::Stop() {
            isRunning = false;
        }

        void CoreEngine::Shutdown() {
            OnShutdown(); 
        }

        void CoreEngine::EngineLoop() {
            while (isRunning) {
                OnUpdate(); 
                OnRender(); 
            }
        }
    } // namespace engine

