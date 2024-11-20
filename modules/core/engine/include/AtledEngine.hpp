#include <Entity.hpp>
#include <EventBus.hpp>
#include <memory>
#include <System.hpp>
#include <vector>
#include <ServiceProvider.hpp>

class AtledEngine {
public:
   AtledEngine();

  void Init();
  void Start();
  void Update(float deltaTime);
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
  ServiceProvider serviceProvider;
  std::vector<std::unique_ptr<System>> systems;
  std::vector<std::shared_ptr<Entity>> entities;
  EventBus eventBus;
};
