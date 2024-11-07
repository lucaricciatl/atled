// Engine.tpp
#include "Engine.hpp"

template <typename InputManager, typename GraphicsManager>
void Engine<InputManager, GraphicsManager>::EngineLoop() {
    // Default loop behavior
    std::cout << "Running engine loop..." << std::endl;
    // Custom logic for processing input, updating state, rendering, etc.

    // Example exit condition
    if (/* some exit condition */) {
        isRunning = false;
    }
}
