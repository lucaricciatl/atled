#include "NewEngine.hpp"

namespace engine {

NewEngine::NewEngine() {}

void NewEngine::Init() {
  for (auto &system : systems) {
    system->Init();
  }
}

void NewEngine::Start() {
  isRunning = true;
  Init();

  // Loop principale
  while (isRunning) {
    // Calcolo del deltaTime
    static auto lastTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    float deltaTime =
        std::chrono::duration<float>(currentTime - lastTime).count();
    lastTime = currentTime;

    Update(deltaTime);
  }

  Shutdown();
}

void NewEngine::Update(float deltaTime) {
  for (auto &system : systems) {
    system->Update(deltaTime);
  }
}

void NewEngine::Shutdown() {
  for (auto &system : systems) {
    system->Shutdown();
  }
}

std::shared_ptr<Entity> NewEngine::CreateEntity() {
  auto entity = std::make_shared<Entity>();
  entities.push_back(entity);
  return entity;
}

void NewEngine::RemoveEntity(std::shared_ptr<Entity> entity) {
  entities.erase(std::remove(entities.begin(), entities.end(), entity),
                 entities.end());
}

void NewEngine::AddSystem(std::unique_ptr<System> system) {
  systems.push_back(std::move(system));
}

EventBus *NewEngine::GetEventBus() { return &eventBus; }
} // namespace engine
