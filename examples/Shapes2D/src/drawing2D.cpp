#include "GraphicsContext.hpp"
#include "graphicsImpl.hpp"

int main() {

  auto graphicsMng = std::make_shared<GraphicsManagerImpl>();
  graphicsMng->Init();

  graphicsMng->RenderLoop();

  return 0;
}




