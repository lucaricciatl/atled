#pragma once

#include <memory>
#include "IEngine.hpp"
#include "InputManagerBuilder.hpp"
#include "GraphicManagerFactory.hpp"
#include "CoreEngine.hpp"
#include "CameraManager.hpp"

using namespace input;
using namespace graphics;

namespace engine {

template <typename T>
class EngineBuilder {
public:
    EngineBuilder() = default;

    // Methods to configure the engine
    EngineBuilder& SetKeyboardType(KeyboardType type);
    EngineBuilder& SetMouseType(MouseType type);
    EngineBuilder& SetGraphicsType(GraphicsType type);
    EngineBuilder& SetCameraType(CameraType type);
    EngineBuilder& SetGraphicsConfig(const GfxConfig& config);
    EngineBuilder& SetTargetFramerate(unsigned int frameRate);

    // Build method to create an instance of the specified engine type
    std::unique_ptr<T> Build();

private:
    KeyboardType keyboardType = KeyboardType::Invalid; // Default type
    MouseType mouseType = MouseType::Invalid;          // Default type
    GraphicsType graphicsType = GraphicsType::Invalid;
    CameraType cameraType = CameraType::Invalid;
    GfxConfig gfxConfig;                              // Default config
    unsigned int targetFramerate = 60;                // Default frame rate
};

// Implementation of the template methods

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetKeyboardType(KeyboardType type) {
    keyboardType = type;
    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetMouseType(MouseType type) {
    mouseType = type;
    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetGraphicsType(GraphicsType type) {
    graphicsType = type;
    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetCameraType(CameraType type) {
    cameraType = type;
    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetGraphicsConfig(const GfxConfig& config) {
    gfxConfig = config;
    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetTargetFramerate(unsigned int frameRate) {
    targetFramerate = frameRate;
    return *this;
}

template <typename T>
std::unique_ptr<T> EngineBuilder<T>::Build() {
    // Build InputManager using InputManagerBuilder
    InputManagerBuilder inputBuilder;
    inputBuilder.SetKeyboardType(keyboardType)
                .SetMouseType(mouseType);
    auto inputManager = inputBuilder.Build();

    // Create GraphicsManager using GraphicsManagerFactory
    auto graphicsManager = GraphicsManagerFactory::CreateGraphicsManager(graphicsType);
    graphicsManager->SetConfigs(gfxConfig);
    graphicsManager->SetTargetFramerate(targetFramerate);

    std::unique_ptr<CameraManager> cameraManager;
    // Create an instance of T with the configured InputManager and GraphicsManager
    return std::make_unique<T>(std::move(inputManager), std::move(graphicsManager),std::move(cameraManager));
}

} // namespace engine
