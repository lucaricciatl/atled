#include "RenderSystem.hpp"

RenderSystem::RenderSystem(graphics::IGraphicManager *graphicsMgr)
    : graphicsManager(graphicsMgr) {
}

void RenderSystem::Init() {
    graphicsManager->Init();
}

void RenderSystem::Update(float deltaTime) {
    graphicsManager->Render();
}
