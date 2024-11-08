// main.cpp
#include "EngineBuilder.hpp"
#include "CoreEngine.hpp"
#include <memory>
#include <Engine.hpp>

int main() {
    engine::EngineBuilder<engine::CoreEngine> builder;

    std::unique_ptr<engine::CoreEngine> engine = builder
        .SetKeyboardType(input::KeyboardType::Raylib)
        .SetMouseType(input::MouseType::Raylib)
        .SetGraphicsType(graphics::GraphicsType::Default)
        .SetTargetFramerate(60) // Set frame rate suitable for the game speed
        .Build();

    engine->Start();

    return 0;
}
