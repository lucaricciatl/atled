#pragma once

#include "CoreEngine.hpp"
#include <memory>
#include "InputManager.hpp"            // Include the full definition of InputManager
#include "IGraphicManager.hpp"          // Include the full definition of IGraphicManager
#include "NBodySimulation.hpp"

class Engine : public engine::CoreEngine {
public:
    using CoreEngine::CoreEngine;  // Inherit CoreEngine's constructors
    ~Engine() override = default;

    // Override virtual functions from CoreEngine
    void OnStart() override;
    void OnUpdate() override;
    void OnRender() override;
    void OnShutdown() override;

    NBodySimulation simulation;
};


