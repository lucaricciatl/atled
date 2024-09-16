#pragma once
#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

#include "CameraManager.hpp"
#include "GraphicsContext.hpp"

namespace graphics {

struct GfxConfig {
  // Static default flag
  static constexpr ConfigFlags defaultFlags = FLAG_VSYNC_HINT;

  // Vector to store window configuration flags
  std::vector<ConfigFlags> WindowConfig;

  // Constructor with default flags
  GfxConfig() {
    WindowConfig.push_back(defaultFlags);  // Initialize with the default flag
  }

  // Constructor to allow custom flags
  GfxConfig(std::vector<ConfigFlags> customFlags) : WindowConfig(customFlags) {}
};

class GraphicsManager {
 public:
  GraphicsManager();
  ~GraphicsManager();
  void SetConfigs(GfxConfig aGfxConfigs);
  void RenderLoop();
  void CameraStep();
  void SetTargetFramerate(unsigned int frameRate);
  std::shared_ptr<GraphicsContext> GetGraphicsContext();

  void Render();
  void Start();
  void Stop();

  std::atomic<bool> mRunning;
  unsigned int mFrameRate;

 private:
  std::unique_ptr<std::thread> mThread;
  std::shared_ptr<GraphicsContext> mContext;
  std::shared_ptr<CameraManager> mCamera;
  std::shared_ptr<GfxConfig> mConfigs;
};
}  // namespace graphics