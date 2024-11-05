// EngineBuilder.cpp
#include "EngineBuilder.hpp"

namespace engine {

EngineBuilder& EngineBuilder::SetKeyboardType(input::KeyboardType type) {
    keyboardType = type;
    return *this;
}

EngineBuilder& EngineBuilder::SetMouseType(input::MouseType type) {
    mouseType = type;
    return *this;
}

EngineBuilder& EngineBuilder::SetGraphicsType(graphics::GraphicsType type) {
    graphicsType = type;
    return *this;
}

EngineBuilder& EngineBuilder::SetGraphicsConfig(const graphics::GfxConfig& config) {
    gfxConfig = config;
    return *this;
}

EngineBuilder& EngineBuilder::SetTargetFramerate(unsigned int frameRate) {
    targetFramerate = frameRate;
    return *this;
}

std::unique_ptr<CoreEngine> EngineBuilder::Build() {
    // Build InputManager using InputManagerBuilder
    input::InputManagerBuilder inputBuilder;
    inputBuilder.SetKeyboardType(keyboardType)
                .SetMouseType(mouseType);
    auto inputManager = inputBuilder.Build();

    // Create GraphicsManager using GraphicsManagerFactory
    auto graphicsManager = graphics::GraphicsManagerFactory::CreateGraphicsManager(graphicsType);
    graphicsManager->SetConfigs(gfxConfig);
    graphicsManager->SetTargetFramerate(targetFramerate);

    // Create CoreEngine with configured InputManager and GraphicsManager
    return std::make_unique<CoreEngine>(std::move(inputManager), std::move(graphicsManager));
}

} // namespace engine
