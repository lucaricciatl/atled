#pragma once
#include "gfx.hpp"
#include "LayerManager.hpp"
#include "IWindow.hpp"

namespace graphics {
class GraphicsContext {
 public:
  GraphicsContext();
  GraphicsContext(int aWindowWidth, int aWindowHeight, const char* aWindowTitle,
                  std::vector<gfx::ConfigFlags> flags); 
  GraphicsContext(int aWindowWidth, int aWindowHeight,
                  const char* aWindowTitle);
  ~GraphicsContext();
  void InitWindowManager();
  void InitWindowManager(std::vector<gfx::ConfigFlags> flags);
  void SetFlag(gfx::ConfigFlags flag);
  // Function to unset a flag (or multiple flags)
  void UnsetFlag(gfx::ConfigFlags flag);
  void SetTitle(const char* title);
  void SetSize(int width, int height);
  int GetWidth() const;
  int GetHeight() const;
  void SetTargetFPS(int fps);
  void Begin() const ;
  void End() const ;
  void Clear(gfx::Color aColor);
  bool isReady;

  LayerManager mLayerManager;
 private:
  //std::unique_ptr<CameraManager> mCamera;
  std::unique_ptr<IWindow> mWindow;
  int windowWidth;
  int windowHeight;
  const char* windowTitle;
  unsigned int currentFlags = 0;

};
}  // namespace graphics