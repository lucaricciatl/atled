
#include "GraphicsContext.hpp"

#include <string_view>

#include "raylib.h"

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
                                 std::vector<raylib::ConfigFlags> flags) {
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

GraphicsContext::~GraphicsContext() { raylib::CloseWindow(); }

void GraphicsContext::InitWindowManager(std::vector<raylib::ConfigFlags> flags) {
  for (auto flag : flags) {
    SetFlag(flag);
  }
  raylib::InitWindow(windowWidth, windowHeight, windowTitle);
}

void GraphicsContext::InitWindowManager() {
  raylib::InitWindow(windowWidth, windowHeight, windowTitle);
}

// Function to unset a flag (or multiple flags)
void GraphicsContext::UnsetFlag(raylib::ConfigFlags flag) {
  currentFlags &= ~flag;         // Unset the specific flag(s)
  raylib::SetConfigFlags(currentFlags);  // Update the window flags
}

void GraphicsContext::SetFlag(raylib::ConfigFlags flag) {
  // Set the configuration flags using the provided flags
  currentFlags |= flag;  // Set the specific flag(s)
  raylib::SetConfigFlags(currentFlags);
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

void GraphicsContext::Begin() const { raylib::BeginDrawing(); }
void GraphicsContext::End() const { raylib::EndDrawing(); }

void GraphicsContext::Clear(raylib::Color aColor) { raylib::ClearBackground(aColor); };

}  // namespace graphics