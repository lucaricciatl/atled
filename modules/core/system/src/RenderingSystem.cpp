#include "RenderSystem.hpp"

RenderSystem::RenderSystem(graphics::IGraphicManager *graphicsMgr)
    : graphicsManager(graphicsMgr) {
  // Popola le liste dei componenti se necessario
}

void RenderSystem::Update(float deltaTime) {
  graphicsManager->BeginFrame();

  for (size_t i = 0; i < renderComponents.size(); ++i) {
    auto &renderComp = renderComponents[i];
    auto &transformComp = transformComponents[i];

    // Renderizza il mesh con la trasformazione corrente
    graphicsManager->RenderMesh(renderComp->mesh, renderComp->material,
                                transformComp->GetMatrix());
  }

  graphicsManager->EndFrame();
}
