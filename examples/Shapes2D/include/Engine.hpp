#include <memory>

#include "CoreEngine.hpp"
#include "IGraphicManager.hpp"  // Include the full definition of IGraphicManager
#include "InputManager.hpp"     // Include the full definition of InputManager

class Engine : public engine::CoreEngine {
   public:
    using CoreEngine::CoreEngine;  // Inherit CoreEngine's constructors
    ~Engine() override = default;

    // Override virtual functions from CoreEngine
    void OnStart() override;
    void OnUpdate() override;
    void OnRender() override;
    void OnShutdown() override;
};
