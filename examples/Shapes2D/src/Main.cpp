// main.cpp
#include "EngineBuilder.hpp"
#include "CoreEngine.hpp"
#include <memory>
#include <engine.hpp>

int main() {
    engine::EngineBuilder<Engine> builder;

    std::unique_ptr<Engine> coreEngine = builder
        .SetKeyboardType(input::KeyboardType::Raylib)
        .SetMouseType(input::MouseType::Raylib)
        .SetGraphicsType(graphics::GraphicsType::Raylib)
        .SetCameraType(graphics::CameraType::Raylib)
        .SetTargetFramerate(60) // Set frame rate suitable for the game speed
        .Build();

    // Run the engine
    coreEngine->Start();
    coreEngine->Shutdown();

    return 0;
}