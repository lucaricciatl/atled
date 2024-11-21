#pragma once

#include <memory>
#include "IEngine.hpp"
#include "InputManagerBuilder.hpp"
#include "GraphicManagerFactory.hpp"
#include "CameraFactory.hpp"
#include "CameraManager.hpp"
#include "CoreEngine.hpp"
#include "CameraManager.hpp"

using namespace input;
using namespace graphics;

namespace engine {

enum class EngineImplementation{
    Raylib
};

template <typename T>
class EngineBuilder {
public:
    EngineBuilder() = default;

    // Methods to configure the engine
    EngineBuilder& SetKeyboardType(KeyboardType type);
    EngineBuilder& SetMouseType(MouseType type);
    EngineBuilder& SetGraphicsType(GraphicsType type);
    EngineBuilder& SetCameraType(CameraType type);
    EngineBuilder& SetGraphicsConfig(const GraphicsConfig& config);
    EngineBuilder& SetTargetFramerate(unsigned int frameRate);
    EngineBuilder& SetWorldType(WorldType type);
    EngineBuilder& SetDefaultImplementation();
    EngineBuilder& SetImplementation(EngineImplementation impl);
    // Build method to create an instance of the specified engine type
    std::unique_ptr<T> Build();

private:
    KeyboardType keyboardType = KeyboardType::Invalid; // Default type
    MouseType mouseType = MouseType::Invalid;          // Default type
    GraphicsType graphicsType = GraphicsType::Invalid;
    CameraType cameraType = CameraType::Invalid;
    WorldType worldType = WorldType::World2D;
    GraphicsConfig gfxConfig;                              // Default config
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
EngineBuilder<T>& EngineBuilder<T>::SetWorldType(WorldType type) {
    worldType = type;
    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetGraphicsConfig(const GraphicsConfig& config) {
    gfxConfig = config;
    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetTargetFramerate(unsigned int frameRate) {
    targetFramerate = frameRate;
    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetDefaultImplementation() {
    return SetKeyboardType(input::KeyboardType::Raylib)
        .SetMouseType(input::MouseType::Raylib)
        .SetGraphicsType(graphics::GraphicsType::Raylib)
        .SetWorldType(graphics::WorldType::World3D)
        .SetTargetFramerate(60);
    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetImplementation(EngineImplementation impl) {
    if (impl == EngineImplementation::Raylib) {
        return SetKeyboardType(input::KeyboardType::Raylib)
            .SetMouseType(input::MouseType::Raylib)
            .SetGraphicsType(graphics::GraphicsType::Raylib)
            .SetWorldType(graphics::WorldType::World3D)
            .SetTargetFramerate(60);
    };
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
    
    auto CameraMng = std::make_shared<CameraManager>();

if (worldType == WorldType::World2D) {
    // Create and add a 2D camera
    auto cam = CameraFactory::createCamera2D(CameraType2D::Raylib);
    CameraMng->AddCamera(cam);
    CameraMng->SetActiveCamera(0);  // Set the newly added camera as active
    std::cout << "Initialized 2D Camera" << std::endl;
}
else if (worldType == WorldType::World3D) {
    // Create and add a 3D camera
    auto cam = CameraFactory::createCamera3D(CameraType3D::Raylib);
    CameraMng->AddCamera(cam);
    CameraMng->SetActiveCamera(0);  // Set the newly added camera as active
    std::cout << "Initialized 3D Camera" << std::endl;
}
else {
    std::cerr << "Error: Unsupported world type!" << std::endl;
}


    graphicsManager->SetCameraMng(CameraMng);


    // Create an instance of T with the configured InputManager and GraphicsManager
    return std::make_unique<T>(std::move(inputManager), std::move(graphicsManager),std::move(CameraMng));
}

} // namespace engine
