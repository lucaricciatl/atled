#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "Component.hpp"
#include "IGraphicManager.hpp"
#include "System.hpp"
#include <vector>

class RenderSystem : public System {
public:
  RenderSystem(graphics::IGraphicManager *graphicsMgr);
  void Init() override;
  void Update(float deltaTime) override;

private:
  graphics::IGraphicManager *graphicsManager;
  // Riferimenti ai componenti

};

#endif // RENDERSYSTEM_HPP
