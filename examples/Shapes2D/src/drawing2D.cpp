#include "GraphicsContext.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "graphicsImpl.hpp"

int main() {

  auto graphicsMng = std::make_shared<GraphicsManagerImpl>();
  graphicsMng->Init();
  
  input::Mouse mouse;
  mouse.Start(); 

  graphicsMng->Start();

  return 0;
}




