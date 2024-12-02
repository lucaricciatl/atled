#include "AtledEngine.hpp"
#include <chrono>
#include "GraphicsManager.hpp"
#include "InputManager.hpp"
#include "InputSystem.hpp"
#include "PhysicsSystem.hpp"
#include "RenderSystem.hpp"
#include "CameraFactory.hpp"
#include "ServiceProvider.hpp"
#include <FrameComponent.hpp>
#include <ResourcesSystem.hpp>

AtledEngine::AtledEngine(
	std::unique_ptr<input::InputManager> inputMgr,
	std::unique_ptr<graphics::IGraphicManager> graphicsMgr,
	std::shared_ptr<graphics::CameraManager> cameraMgr,
    std::shared_ptr<resources::ResourceManager> resMgr)
	:serviceProvider(std::make_shared<ServiceProvider>())
	{
	// Convert unique_ptr to shared_ptr
	auto sharedInputMgr = std::shared_ptr<input::InputManager>(std::move(inputMgr));
	auto sharedGraphicsMgr = std::shared_ptr<graphics::IGraphicManager>(std::move(graphicsMgr));
	auto sharedCameraMgr = std::shared_ptr<graphics::CameraManager>(std::move(cameraMgr));
	auto sharedResourcesMgr = std::shared_ptr<resources::ResourceManager>(std::move(resMgr));

	// Provide shared pointers to the service provider
	serviceProvider->Provide(sharedInputMgr);
	serviceProvider->Provide(sharedGraphicsMgr);
	serviceProvider->Provide(sharedCameraMgr);
	serviceProvider->Provide(sharedResourcesMgr);

	// Add systems using shared pointers
	AddSystem(std::make_unique<InputSystem>(sharedInputMgr.get(), GetEventBus()));
	AddSystem(std::make_unique<PhysicsSystem>(GetEventBus()));
	AddSystem(std::make_unique<RenderSystem>(sharedGraphicsMgr.get()));
	AddSystem(std::make_unique<ResourceSystem>(sharedResourcesMgr.get()));

	for (auto& system : systems) {
		system->Init();
	}
}


void AtledEngine::Init() {

	for (const auto& entity : entities) {
		if (entity->GetParent() == nullptr) {
			entity->Init();
		}
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

void AtledEngine::UpdateSystems(float deltaTime) {
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
	entity->SetServiceProvider(serviceProvider);
	entity->AddComponent<FrameComponent>();
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

// Update all entities
void AtledEngine::UpdateEntities(double deltaTime) {
	for (auto& entity : entities) {
		// update only if the entity does not have a parent,
		// the child entity are updated in cascade to they're 
		// parents
		if (entity->GetParent() != nullptr) {
			entity->Update(deltaTime);
		}
	}
}

void AtledEngine::Update(double deltatime) {
	UpdateSystems(deltatime);
	UpdateEntities(deltatime);
}