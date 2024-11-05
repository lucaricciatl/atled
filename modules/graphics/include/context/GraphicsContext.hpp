#pragma once
#include "LayerManager.hpp"
#include "CameraBase.hpp"
#include "IWindow.hpp"

namespace graphics {
class GraphicsContext {
 public:
  GraphicsContext();
  GraphicsContext(int aWindowWidth, int aWindowHeight, const char* aWindowTitle,
                  std::vector<::ConfigFlags> flags); 
  GraphicsContext(int aWindowWidth, int aWindowHeight,
                  const char* aWindowTitle);
  ~GraphicsContext();
  // init
  void InitWindowManager();
  void InitWindowManager(std::vector<::ConfigFlags> flags);
  void InitWindowManager(::ConfigFlags flags);

  // set
  void SetFlag(::ConfigFlags flag);
  void SetTitle(const char* title);
  void SetSize(int width, int height);
  // unset 
  void UnsetFlag(::ConfigFlags flag);
  // get
  int GetWidth() const;
  int GetHeight() const;

  void SetTargetFPS(int fps);
  void BeginDrawing() const;
  void EndDrawing() const ;
  void Clear(::Color aColor);
  bool isReady;
  LayerManager mLayerManager;

 private:
  std::unique_ptr<IWindow> mWindow;
  int windowWidth;
  int windowHeight;
  const char* windowTitle;
  unsigned int currentFlags = 0;
};
}  // namespace graphics