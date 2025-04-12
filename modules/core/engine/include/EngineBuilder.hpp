#pragma once

#include <iostream>
#include <memory>

#include "CameraFactory.hpp"
#include "CameraManager.hpp"
#include "CoreEngine.hpp"
#include "GraphicManagerFactory.hpp"
#include "IEngine.hpp"
#include "IResourceManager.hpp"
#include "InputManagerBuilder.hpp"
#include "PhysicsManager.hpp"
#include "ResourceManagerBuilder.hpp"
#include "nlohmann/json.hpp"
#include <fstream>

using namespace input;
using namespace graphics;
using namespace resources;

namespace engine {

enum class EngineImplementation { Raylib };

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
    EngineBuilder& SetWorldType(WorldType type);
    EngineBuilder& SetDefaultImplementation();
    EngineBuilder& SetDefault2DImplementation();
    EngineBuilder& SetImplementation(EngineImplementation impl);
    EngineBuilder<T>& Configure();
    EngineBuilder<T>& InitializeFromJson(const nlohmann::json& json);
    EngineBuilder<T>& InitializeFromJsonFile(const std::string& filePath);
    // Build method to create an instance of the specified engine type
    std::unique_ptr<T> Build();

   private:
    KeyboardType keyboardType = KeyboardType::Invalid;
    MouseType mouseType = MouseType::Invalid;
    GraphicsType graphicsType = GraphicsType::Invalid;
    CameraType cameraType = CameraType::Invalid;
    WorldType worldType = WorldType::World2D;
    ResourceManagerType resourceManagerType = ResourceManagerType::Default;
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
EngineBuilder<T>& EngineBuilder<T>::SetDefault2DImplementation() {
    return SetKeyboardType(KeyboardType::Raylib)
        .SetMouseType(MouseType::Raylib)
        .SetGraphicsType(GraphicsType::Raylib)
        .SetWorldType(WorldType::World2D)
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
EngineBuilder<T>& EngineBuilder<T>::Configure() {
    InitializeFromJsonFile("./config.json");
    return *this;
}

    template <typename T>
std::unique_ptr<T> EngineBuilder<T>::Build() {
    // Build InputManager using InputManagerBuilder
    InputManagerBuilder inputBuilder;
    inputBuilder.SetKeyboardType(keyboardType).SetMouseType(mouseType);
    auto inputManager = inputBuilder.Build();

    // Build GraphicsManager using GraphicsManagerFactory
    auto graphicsManager = GraphicsManagerFactory::CreateGraphicsManager(graphicsType);
    graphicsManager->SetConfigs(gfxConfig);
    graphicsManager->SetTargetFramerate(targetFramerate);

    // Build ResourceManager using ResourceManagerBuilder
    ResourceManagerBuilder resourceBuilder;
    resourceBuilder.SetType(resourceManagerType);
    auto resourceManager = resourceBuilder.Build();

    auto physicsManager = std::make_shared<physics::PhysicsManager>();
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

        cam->SetPosition({5.0f, 5.0f, 5.0f});          // Camera position
        cam->SetTarget({0.0f, 0.0f, 0.0f});            // Camera looking at point
        cam->SetUp({0.0f, 1.0f, 0.0f});                // Camera up vector
        cam->SetFovy(45.0f);                           // Field of view Y
        cam->SetCameraProjection(CAMERA_PERSPECTIVE);  // Perspective projection

        std::cout << "Initialized 3D Camera" << std::endl;
    } else {
        throw std::runtime_error("Unsupported world type specified!");
    }

    // Associate CameraManager with GraphicsManager
    graphicsManager->SetCameraMng(cameraManager);

    // Create and return the engine instance
    return std::make_unique<T>(std::move(inputManager), std::move(graphicsManager), std::move(cameraManager),
                               std::move(resourceManager), std::move(physicsManager));
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::InitializeFromJson(const nlohmann::json& json) {
    // Configure keyboard type
    if (json.contains("keyboardType")) {
        std::string keyType = json["keyboardType"].get<std::string>();
        if (keyType == "Raylib") SetKeyboardType(KeyboardType::Raylib);
        // Add additional conditions as needed
    }

    // Configure mouse type
    if (json.contains("mouseType")) {
        std::string mouseTypeStr = json["mouseType"].get<std::string>();
        if (mouseTypeStr == "Raylib") SetMouseType(MouseType::Raylib);
    }

    // Configure graphics type
    if (json.contains("graphicsType")) {
        std::string gfxType = json["graphicsType"].get<std::string>();
        if (gfxType == "Raylib") SetGraphicsType(GraphicsType::Raylib);
    }

    // Configure camera type
    if (json.contains("cameraType")) {
        std::string camType = json["cameraType"].get<std::string>();
        if (camType == "Raylib") SetCameraType(CameraType::Raylib);
    }

    // Configure world type
    if (json.contains("worldType")) {
        std::string worldStr = json["worldType"].get<std::string>();
        if (worldStr == "World2D")
            SetWorldType(WorldType::World2D);
        else if (worldStr == "World3D")
            SetWorldType(WorldType::World3D);
    }

    // Configure resource manager type
    if (json.contains("resourceManagerType")) {
        std::string resMgrType = json["resourceManagerType"].get<std::string>();
        if (resMgrType == "Default") SetResourceManagerType(ResourceManagerType::Default);
    }

    // Configure target framerate
    if (json.contains("targetFramerate")) {
        SetTargetFramerate(json["targetFramerate"].get<unsigned int>());
    }

    // Manually extract the graphics configuration values
    if (json.contains("graphicsConfig")) {
        const auto& gfxJson = json["graphicsConfig"];

        if (gfxJson.contains("width")) gfxConfig.width = gfxJson["width"].get<int>();
        if (gfxJson.contains("height")) gfxConfig.height = gfxJson["height"].get<int>();
        if (gfxJson.contains("fullscreen")) gfxConfig.fullscreen = gfxJson["fullscreen"].get<bool>();
        if (gfxJson.contains("vsync")) gfxConfig.vsync = gfxJson["vsync"].get<bool>();
        if (gfxJson.contains("antialiasing")) gfxConfig.antialiasing = gfxJson["antialiasing"].get<int>();

        // Process custom configuration flags, if provided.
        if (gfxJson.contains("windowConfig") && gfxJson["windowConfig"].is_array()) {
            // Clear the default flags if custom ones are provided
            gfxConfig.WindowConfig.clear();
            for (const auto& flagValue : gfxJson["windowConfig"]) {
                std::string flagStr = flagValue.get<std::string>();
                // Map the string to the corresponding raylib::ConfigFlags value
                if (flagStr == "FLAG_VSYNC_HINT") {
                    gfxConfig.WindowConfig.push_back(raylib::ConfigFlags::FLAG_VSYNC_HINT);
                } else if (flagStr == "FLAG_MSAA_4X_HINT") {
                    gfxConfig.WindowConfig.push_back(raylib::ConfigFlags::FLAG_MSAA_4X_HINT);
                } else if (flagStr == "FLAG_WINDOW_HIGHDPI") {
                    gfxConfig.WindowConfig.push_back(raylib::ConfigFlags::FLAG_WINDOW_HIGHDPI);
                } else if (flagStr == "FLAG_WINDOW_RESIZABLE") {
                    gfxConfig.WindowConfig.push_back(raylib::ConfigFlags::FLAG_WINDOW_RESIZABLE);
                } else if (flagStr == "FLAG_WINDOW_TRANSPARENT") {
                    gfxConfig.WindowConfig.push_back(raylib::ConfigFlags::FLAG_WINDOW_TRANSPARENT);
                } else if (flagStr == "FLAG_WINDOW_UNDECORATED") {
                    gfxConfig.WindowConfig.push_back(raylib::ConfigFlags::FLAG_WINDOW_UNDECORATED);
                } else if (flagStr == "FLAG_FULLSCREEN_MODE") {
                    gfxConfig.WindowConfig.push_back(raylib::ConfigFlags::FLAG_FULLSCREEN_MODE);
                } else {
                    // Optionally, handle unknown flags here.
                    std::cerr << "Warning: Unknown config flag \"" << flagStr << "\" provided." << std::endl;
                }
            }
        }
    }

    return *this;
}

template <typename T>
EngineBuilder<T>& EngineBuilder<T>::InitializeFromJsonFile(const std::string& filePath) {
    std::ifstream fileStream(filePath);
    nlohmann::json jsonData;

    if (!fileStream.is_open()) {
        // JSON file not found. Create a default JSON configuration.
        jsonData = {{"keyboardType", "Raylib"},
                    {"mouseType", "Raylib"},
                    {"graphicsType", "Raylib"},
                    {"cameraType", "Raylib"},
                    {"worldType", "World3D"},
                    {"resourceManagerType", "Default"},
                    {"targetFramerate", 60},
                    {"graphicsConfig",
                     {{"width", 800},
                      {"height", 600},
                      {"fullscreen", false},
                      {"vsync", true},
                      {"antialiasing", 0},
                      {"windowConfig", {"FLAG_VSYNC_HINT"}}}}};

        // Write the default JSON to the file
        std::ofstream outFile(filePath);
        if (!outFile.is_open()) {
            throw std::runtime_error("Unable to create JSON file: " + filePath);
        }
        outFile << jsonData.dump(4);  // pretty print with 4-space indentation
        outFile.close();

        std::cout << "Default configuration written to " << filePath << std::endl;
    } else {
        // Read existing JSON file
        fileStream >> jsonData;
        fileStream.close();
    }

    return InitializeFromJson(jsonData);
}

}  // namespace engine
