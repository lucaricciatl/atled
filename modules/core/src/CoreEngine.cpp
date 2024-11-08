// CoreEngine.cpp
#include "CoreEngine.hpp"
#include <iostream>


namespace engine {

	CoreEngine::CoreEngine(std::unique_ptr<input::InputManager> inputMgr,
		std::unique_ptr<graphics::IGraphicManager> graphicsMgr)
		: inputManager(std::move(inputMgr)),
		graphicsManager(std::move(graphicsMgr)),
		isRunning(false),
		isReady(false) {}

	void CoreEngine::Init() {
		std::cout << "Initializing Core Engine..." << std::endl;
		isReady = true;  // Set the engine as ready after initialization
		graphicsManager->Init();
	}

	void CoreEngine::Start() {
		std::cout << "Starting Core Engine..." << std::endl;

		if (!isReady) {
			Init();
		}

		isRunning = true;

		while (isRunning) {
			EngineLoop();
		}

		Shutdown();  // Cleanup after the loop ends
	}

	void CoreEngine::Shutdown() {
		std::cout << "Shutting down Core Engine..." << std::endl;
		isRunning = false;
		// Additional cleanup logic here
	}

	void CoreEngine::Stop() {
		std::cout << "Stopping Core Engine..." << std::endl;
		isRunning = false;  // This will exit the main loop
	}

}