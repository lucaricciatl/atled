#include "CameraManager.hpp"
#include "Component.hpp"
#include "NewEngine.hpp"
#include "Entity.hpp"
#include "GraphicsManager.hpp"
#include "InputManager.hpp"
#include "InputSystem.hpp"
#include "PhysicsSystem.hpp"
#include "RenderSystem.hpp"
#include "ServiceProvider.hpp"
#include <memory>
#include "EventBus.hpp"

int main() {
  // Create the managers
  auto inputManager = std::make_shared<input::InputManager>(input::KeyboardType::Raylib, input::MouseType::Raylib);
  auto graphicsManager = std::make_shared<graphics::GraphicsManager>();
  auto cameraManager = std::make_shared<graphics::CameraManager>();

  // Initialize the service provider
  ServiceProvider serviceProvider;
  serviceProvider.Provide(inputManager);
  serviceProvider.Provide(graphicsManager);
  serviceProvider.Provide(cameraManager);

  // Create the NewEngine
  NewEngine coreEngine(serviceProvider);

  // Add systems to the engine
 coreEngine.AddSystem(std::make_unique<InputSystem>(inputManager.get(),
                                                     coreEngine.GetEventBus()));
  coreEngine.AddSystem(
      std::make_unique<PhysicsSystem>(coreEngine.GetEventBus()));
  coreEngine.AddSystem(std::make_unique<RenderSystem>(graphicsManager.get()));

  // Create an entity and add components
  auto entity = coreEngine.CreateEntity();

  // Start the engine (game loop begins)
  coreEngine.Start();

  return 0;
}
