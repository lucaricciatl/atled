#pragma once
#include "LayerManager.hpp"
#include "ICamera.hpp"
#include "IWindow.hpp"
#include "GraphicsConfig.hpp"

namespace graphics {
class GraphicsContext {
 public:
  GraphicsContext();
  GraphicsContext(int aWindowWidth, int aWindowHeight, const char* aWindowTitle,
                    std::shared_ptr<GraphicsConfig> flags);
  GraphicsContext(int aWindowWidth, int aWindowHeight,
                  const char* aWindowTitle);
  ~GraphicsContext();
  // init
  void InitWindowManager();
  void SetFlags(std::shared_ptr<GraphicsConfig> flags);

  // set
  void SetFlag(raylib::ConfigFlags flag);
  void SetTitle(const char* title);
  void SetSize(int width, int height);
  // unset 
  void UnsetFlag(raylib::ConfigFlags flag);
  // get
  int GetWidth() const;
  int GetHeight() const;

  void SetTargetFPS(int fps);
  void BeginDrawing() const;
  void EndDrawing() const ;
  void Clear(raylib::Color aColor);
  bool isReady;

 private:
  std::unique_ptr<IWindow> mWindow;
  int windowWidth;
  int windowHeight;
  const char* windowTitle;
  unsigned int currentFlags = 0;
};
}  // namespace graphics