#ifndef INPUTSYSTEM_HPP
#define INPUTSYSTEM_HPP

#include "EventBus.hpp"
#include "InputManager.hpp"
#include "System.hpp"
#include <thread>
#include <atomic>

class InputSystem : public System {
public:
	InputSystem(input::InputManager* inputMgr, EventBus* eventBus);
	~InputSystem();

	void Init() override;           // Initialize the input manager
	void Update(float deltaTime) override; // Update logic for processing input
	void Start();                   // Start the threaded update
	void Stop();                    // Stop the threaded update

private:
	float GetDeltaTime();           // Calculate delta time for updates

	input::InputManager* inputManager; // Pointer to the input manager
	EventBus* eventBus;                // Pointer to the event bus

	std::atomic<bool> isRunning;    // Atomic flag to control thread execution
	std::thread updateThread;       // Thread for running the update logic
};

#endif // INPUTSYSTEM_HPP
