#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "Components.hpp"
#include "IGraphicManager.hpp"
#include "System.hpp"
#include <vector>

class RenderSystem : public System {
public:
  RenderSystem(graphics::IGraphicManager *graphicsMgr);

  void Update(float deltaTime) override;

private:
  graphics::IGraphicManager *graphicsManager;
  // Riferimenti ai componenti
  std::vector<std::shared_ptr<RenderComponent>> renderComponents;
  std::vector<std::shared_ptr<TransformComponent>> transformComponents;
};

#endif // RENDERSYSTEM_HPP
