#ifndef ATLEDENGINE_HPP
#define ATLEDENGINE_HPP

#include <Entity.hpp>
#include <EventBus.hpp>
#include <ResourceManager.hpp>
#include <ServiceProvider.hpp>
#include <System.hpp>
#include <memory>
#include <vector>

#include "PhysicsManager.hpp"

class AtledEngine {
   public:
    AtledEngine(std::unique_ptr<input::InputManager> inputMgr, std::unique_ptr<graphics::IGraphicManager> graphicsMgr,
                std::shared_ptr<graphics::CameraManager> cameraMgr, std::shared_ptr<resources::ResourceManager> resMgr,
                std::shared_ptr<physics::PhysicsManager> physicsManager);

    void Init();
    void Start();
    void Update(double deltatime);
    void UpdateSystems(float deltaTime);
    void UpdateEntities(double deltaTime);
    void Shutdown();

    // Managing entities
    std::shared_ptr<Entity> CreateEntity();
    void RemoveEntity(std::shared_ptr<Entity> entity);

    // Adding systems
    void AddSystem(std::unique_ptr<System> system);

    // Access to EventBus
    EventBus *GetEventBus();

   private:
    bool isRunning = false;
    std::shared_ptr<ServiceProvider> serviceProvider;
    std::vector<std::unique_ptr<System>> systems;
    std::vector<std::shared_ptr<Entity>> entities;
    EventBus eventBus;
};

#endif ATLEDENGINE_HPP
