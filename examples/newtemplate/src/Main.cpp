#include "CameraManager.hpp"
#include "Component.hpp"
#include "AtledEngine.hpp"
#include "Entity.hpp"

#include <memory>
#include "EventBus.hpp"

int main() {

  AtledEngine coreEngine;

  // Create an entity and add components
  auto entity = coreEngine.CreateEntity();

  // Start the engine (game loop begins)
  coreEngine.Start();

  return 0;
}
