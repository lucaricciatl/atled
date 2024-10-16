
#include "GraphicsContext.hpp"
#include "CameraBase.hpp"
#include "CameraFactory.hpp"
#include <string_view>
#include "windowFactory.hpp"
#include "Camera2D.hpp"
#include "Camera3D.hpp"
#include "glwp.hpp"

namespace {
static constexpr int defaultHeight = 420;
static constexpr int defaultWidth = 680;
static constexpr const char* defaultTitle = "Window";
}  // namespace

namespace graphics {
GraphicsContext::GraphicsContext() {
  windowWidth = defaultWidth;
  windowHeight = defaultHeight;
  windowTitle = defaultTitle;
}

GraphicsContext::GraphicsContext(int aWindowWidth, int aWindowHeight,
                                 const char* aWindowTitle,
                                 std::vector<glwp::ConfigFlags> flags) {
  windowWidth = aWindowWidth;
  windowHeight = aWindowHeight;
  windowTitle = aWindowTitle;
  for (auto flag : flags) {
    SetFlag(flag);
  }
  InitWindowManager();
}

GraphicsContext::GraphicsContext(int aWindowWidth, int aWindowHeight,
                                 const char* aWindowTitle) {
  windowWidth = aWindowWidth;
  windowHeight = aWindowHeight;
  windowTitle = aWindowTitle;
}

GraphicsContext::~GraphicsContext() { mWindow->CloseWindow(); }

void GraphicsContext::InitWindowManager(std::vector<::ConfigFlags> flags) {
  for (auto flag : flags) {
    SetFlag(flag);
  }
  InitWindowManager();
}

void GraphicsContext::InitWindowManager() {
  mWindow = WindowFactory::CreateWindow(WindowType::Raylib);
  mCamera = CameraFactory::createCamera(CameraType::CAMERA_2D);
  if (mWindow) {
    mWindow->InitWindow(windowWidth, windowHeight, windowTitle);
  }
}

void GraphicsContext::UnsetFlag(ConfigFlags flag) {
  currentFlags &= ~flag;         
  SetConfigFlags(currentFlags);  
}

void GraphicsContext::SetFlag(ConfigFlags flag) {
  currentFlags |= flag; 
  ::SetConfigFlags(currentFlags);
}

void GraphicsContext::SetTitle(const char* title) {
  windowTitle = title;
}

void GraphicsContext::SetSize(int width, int height) {
  windowWidth = width;
  windowHeight = height;
}

int GraphicsContext::GetWidth() const { return windowWidth; }

std::shared_ptr<CameraBase> GraphicsContext::GetCamera() {
  return mCamera;
}

int GraphicsContext::GetHeight() const { return windowHeight; }

void GraphicsContext::BeginDrawing() const { ::BeginDrawing(); }
void GraphicsContext::EndDrawing() const { ::EndDrawing(); }

void GraphicsContext::Clear(Color aColor) { ::ClearBackground(aColor); };

}  // namespace graphics