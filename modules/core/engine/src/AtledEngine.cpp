#include "AtledEngine.hpp"
#include <chrono>
#include "GraphicsManager.hpp"
#include "GraphicsManager.hpp"
#include "InputManager.hpp"
#include "InputSystem.hpp"
#include "PhysicsSystem.hpp"
#include "RenderSystem.hpp"
#include "CameraFactory.hpp"
#include "ServiceProvider.hpp"

AtledEngine::AtledEngine()
    : isRunning(false) {
    auto inputManager = std::make_shared<input::InputManager>(input::KeyboardType::Raylib, input::MouseType::Raylib);
    auto graphicsManager = std::make_shared<graphics::GraphicsManager>();
    auto cameraManager = std::make_shared<graphics::CameraManager>();
    auto CameraMng = std::make_shared<graphics::CameraManager>();

        auto cam = graphics::CameraFactory::createCamera2D(graphics::CameraType2D::Raylib);
        CameraMng->AddCamera(cam);
        CameraMng->SetActiveCamera(0);  // Set the newly added camera as active
        graphicsManager->SetCameraMng(CameraMng);
    serviceProvider.Provide(inputManager);
    serviceProvider.Provide(graphicsManager);
    serviceProvider.Provide(cameraManager);
    // Add systems to the engine
    AddSystem(std::make_unique<InputSystem>(inputManager.get(),
        GetEventBus()));
    AddSystem(
        std::make_unique<PhysicsSystem>(GetEventBus()));
    AddSystem(std::make_unique<RenderSystem>(graphicsManager.get()));
}

void AtledEngine::Init() {
    for (auto& system : systems) {
        system->Init();
    }
}

void AtledEngine::Start() {
    isRunning = true;
    Init();

    // Main loop
    while (isRunning) {
        // Calculate deltaTime
        static auto lastTime = std::chrono::high_resolution_clock::now();
        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;
        Update(deltaTime);
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // Sleep for ~16ms (60 FPS)

    }

    Shutdown();
}

void AtledEngine::Update(float deltaTime) {
    for (auto& system : systems) {
        system->Update(deltaTime);
    }
}

void AtledEngine::Shutdown() {
    for (auto& system : systems) {
        system->Shutdown();
    }
}

std::shared_ptr<Entity> AtledEngine::CreateEntity() {
    auto entity = std::make_shared<Entity>();
    entities.push_back(entity);
    return entity;
}

void AtledEngine::RemoveEntity(std::shared_ptr<Entity> entity) {
    entities.erase(std::remove(entities.begin(), entities.end(), entity),
        entities.end());
}

void AtledEngine::AddSystem(std::unique_ptr<System> system) {
    systems.push_back(std::move(system));
}

EventBus* AtledEngine::GetEventBus() {
    return &eventBus;
}
