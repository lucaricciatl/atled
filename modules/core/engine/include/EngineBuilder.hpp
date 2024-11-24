#pragma once

#include <memory>
#include <iostream>
#include "IEngine.hpp"
#include "InputManagerBuilder.hpp"
#include "GraphicManagerFactory.hpp"
#include "CameraFactory.hpp"
#include "CameraManager.hpp"
#include "CoreEngine.hpp"
#include "IResourceManager.hpp"
#include "ResourceManagerBuilder.hpp"

using namespace input;
using namespace graphics;
using namespace resources;

namespace engine {

enum class EngineImplementation {
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
    EngineBuilder& SetResourceManagerType(ResourceManagerType type);
    EngineBuilder &SetWorldType(WorldType type);
    EngineBuilder& SetDefaultImplementation();
    EngineBuilder& SetImplementation(EngineImplementation impl);

    // Build method to create an instance of the specified engine type
    std::unique_ptr<T> Build();

private:
    KeyboardType keyboardType = KeyboardType::Invalid;
    MouseType mouseType = MouseType::Invalid;
    GraphicsType graphicsType = GraphicsType::Invalid;
    CameraType cameraType = CameraType::Invalid;
    WorldType worldType = WorldType::World2D;
    ResourceManagerType resourceManagerType  = ResourceManagerType::Default;
    GraphicsConfig gfxConfig;
    unsigned int targetFramerate = 60;

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
EngineBuilder<T>& EngineBuilder<T>::SetResourceManagerType(ResourceManagerType type) {
    resourceManagerType = type;
    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetDefaultImplementation() {
    return SetKeyboardType(KeyboardType::Raylib)
        .SetMouseType(MouseType::Raylib)
        .SetGraphicsType(GraphicsType::Raylib)
        .SetWorldType(WorldType::World3D)
        .SetResourceManagerType(ResourceManagerType::Default)
        .SetTargetFramerate(60);
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::SetImplementation(EngineImplementation impl) {
    if (impl == EngineImplementation::Raylib) {
        return SetKeyboardType(KeyboardType::Raylib)
            .SetMouseType(MouseType::Raylib)
            .SetGraphicsType(GraphicsType::Raylib)
            .SetWorldType(WorldType::World3D)
            .SetResourceManagerType(ResourceManagerType::Default)
            .SetTargetFramerate(60);
    }
    return *this;
}

template <typename T>
std::unique_ptr<T> EngineBuilder<T>::Build() {
    // Build InputManager using InputManagerBuilder
    InputManagerBuilder inputBuilder;
    inputBuilder.SetKeyboardType(keyboardType)
                .SetMouseType(mouseType);
    auto inputManager = inputBuilder.Build();

    // Build GraphicsManager using GraphicsManagerFactory
    auto graphicsManager = GraphicsManagerFactory::CreateGraphicsManager(graphicsType);
    graphicsManager->SetConfigs(gfxConfig);
    graphicsManager->SetTargetFramerate(targetFramerate);

    // Build ResourceManager using ResourceManagerBuilder
    ResourceManagerBuilder resourceBuilder;
    resourceBuilder.SetType(resourceManagerType);
    auto resourceManager = resourceBuilder.Build();

    // Configure CameraManager
    auto cameraManager = std::make_shared<CameraManager>();
    if (worldType == WorldType::World2D) {
        auto cam = CameraFactory::createCamera2D(CameraType2D::Raylib);
        cameraManager->AddCamera(cam);
        cameraManager->SetActiveCamera(0);
        std::cout << "Initialized 2D Camera" << std::endl;
    } else if (worldType == WorldType::World3D) {
        auto cam = CameraFactory::createCamera3D(CameraType3D::Raylib);
        cameraManager->AddCamera(cam);
        cameraManager->SetActiveCamera(0);
        std::cout << "Initialized 3D Camera" << std::endl;
    } else {
        throw std::runtime_error("Unsupported world type specified!");
    }

    // Associate CameraManager with GraphicsManager
    graphicsManager->SetCameraMng(cameraManager);

    // Create and return the engine instance
    return std::make_unique<T>(
        std::move(inputManager), 
        std::move(graphicsManager), 
        std::move(cameraManager), 
        std::move(resourceManager)
    );
}



} // namespace engine
