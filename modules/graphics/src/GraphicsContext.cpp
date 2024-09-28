
#include "GraphicsContext.hpp"

#include <string_view>
#include "windowFactory.hpp"
#include "gfx.hpp"

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
                                 std::vector<gfx::ConfigFlags> flags) {
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

void GraphicsContext::InitWindowManager(std::vector<gfx::ConfigFlags> flags) {
  for (auto flag : flags) {
    SetFlag(flag);
  }
  InitWindowManager();
}

void GraphicsContext::InitWindowManager() {
  // Create the window and store it in the member variable
  mWindow = WindowFactory::CreateWindow(WindowType::Raylib);

  // Initialize the window with dimensions and title
  if (mWindow) {
    mWindow->InitWindow(windowWidth, windowHeight, windowTitle);
  }
}

// Function to unset a flag (or multiple flags)
void GraphicsContext::UnsetFlag(gfx::ConfigFlags flag) {
  currentFlags &= ~flag;         // Unset the specific flag(s)
  SetConfigFlags(currentFlags);  // Update the window flags
}

void GraphicsContext::SetFlag(gfx::ConfigFlags flag) {
  // Set the configuration flags using the provided flags
  currentFlags |= flag;  // Set the specific flag(s)
  gfx::SetConfigFlags(currentFlags);
}

void GraphicsContext::SetTitle(const char* title) {
  windowTitle = title;
}

void GraphicsContext::SetSize(int width, int height) {
  windowWidth = width;
  windowHeight = height;
}

int GraphicsContext::GetWidth() const { return windowWidth; }

int GraphicsContext::GetHeight() const { return windowHeight; }

void GraphicsContext::Begin() const { gfx::BeginDrawing(); }
void GraphicsContext::End() const { gfx::EndDrawing(); }

void GraphicsContext::Clear(Color aColor) { gfx::ClearBackground(aColor); };

}  // namespace graphics