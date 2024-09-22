#pragma once
#include "raylib.h"
#include "LayerManager.hpp"

namespace graphics {
class GraphicsContext {
 public:
  GraphicsContext();
  GraphicsContext(int aWindowWidth, int aWindowHeight, const char* aWindowTitle,
                  std::vector<raylib::ConfigFlags> flags); 
  GraphicsContext(int aWindowWidth, int aWindowHeight,
                  const char* aWindowTitle);
  ~GraphicsContext();
  void InitWindowManager();
  void InitWindowManager(std::vector<raylib::ConfigFlags> flags);
  void SetFlag(raylib::ConfigFlags flag);
  // Function to unset a flag (or multiple flags)
  void UnsetFlag(raylib::ConfigFlags flag);
  void SetTitle(const char* title);
  void SetSize(int width, int height);
  int GetWidth() const;
  int GetHeight() const;
  void SetTargetFPS(int fps);
  void Begin() const ;
  void End() const ;
  void Clear(raylib::Color aColor);
  bool isReady;

  LayerManager mLayerManager;
 private:
  int windowWidth;
  int windowHeight;
  const char* windowTitle;
  unsigned int currentFlags = 0;

};
}  // namespace graphics