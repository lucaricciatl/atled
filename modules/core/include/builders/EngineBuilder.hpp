// EngineBuilder.hpp
#pragma once

#include <memory>
#include "CoreEngine.hpp"
#include "InputManagerBuilder.hpp"
#include "GraphicManagerFactory.hpp"

namespace engine {

class EngineBuilder {
public:
    EngineBuilder() = default;

    // Methods to configure the engine
    EngineBuilder& SetKeyboardType(input::KeyboardType type);
    EngineBuilder& SetMouseType(input::MouseType type);
    EngineBuilder& SetGraphicsType(graphics::GraphicsType type);
    EngineBuilder& SetGraphicsConfig(const graphics::GfxConfig& config);
    EngineBuilder& SetTargetFramerate(unsigned int frameRate);

    // Build method to create the CoreEngine instance
    std::unique_ptr<CoreEngine> Build();

private:
    input::KeyboardType keyboardType = input::KeyboardType::Raylib; // Default type
    input::MouseType mouseType = input::MouseType::Raylib;          // Default type
    graphics::GraphicsType graphicsType = graphics::GraphicsType::Default;
    graphics::GfxConfig gfxConfig;                                  // Default config
    unsigned int targetFramerate = 60;                              // Default frame rate
};

} // namespace engine
