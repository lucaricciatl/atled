#pragma once
#include "gfx.hpp"
#include "LayerManager.hpp"
#include "CameraBase.hpp"
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
  // init
  void InitWindowManager();
  void InitWindowManager(std::vector<gfx::ConfigFlags> flags);

  // set
  void SetFlag(gfx::ConfigFlags flag);
  void SetTitle(const char* title);
  void SetSize(int width, int height);
  // unset 
  void UnsetFlag(gfx::ConfigFlags flag);
  // get
  std::shared_ptr<CameraBase> GetCamera();
  int GetWidth() const;
  int GetHeight() const;

  void SetTargetFPS(int fps);
  void BeginDrawing() const;
  void EndDrawing() const ;
  void Clear(gfx::Color aColor);
  bool isReady;
  LayerManager mLayerManager;

 private:
  std::shared_ptr<CameraBase> mCamera;
  std::unique_ptr<IWindow> mWindow;
  int windowWidth;
  int windowHeight;
  const char* windowTitle;
  unsigned int currentFlags = 0;

};
}  // namespace graphics