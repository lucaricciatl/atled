#pragma once
#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

#include "GraphicsContext.hpp"
#include "IDisplay.hpp"
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
  void SetTargetFramerate(unsigned int frameRate);
  std::shared_ptr<GraphicsContext> GetGraphicsContext();
  virtual void Init();
  virtual void Render();
  void Start();
  void Stop();

  std::atomic<bool> mRunning;
  unsigned int mFrameRate;

  // drawing methods
  void AddArc(const int& aLayerId, std::shared_ptr<Arc> aArc);
  void AddCircle(const int& aLayerId, std::shared_ptr<Circle> aCircle);
  void AddRectangle(const int& aLayerId, std::shared_ptr<Rectangle> aRectangle);
  void AddLine(const int& aLayerId, std::shared_ptr<Line> aLine);
  void AddPolyline(const int& aLayerId, std::shared_ptr<Polyline> aPolyline);
  void AddTriangle(const int& aLayerId, std::shared_ptr<Triangle> aTriangle);
  void AddPolygon(const int& aLayerId, std::shared_ptr<Polygon> aPolygon);
  void DrawLayer(const int& aLayerId);
  void Clear(::Color aColor);

 protected:
  std::unique_ptr<std::thread> mThread;
  std::shared_ptr<GraphicsContext> mContext;
  std::shared_ptr<GfxConfig> mConfigs;
  std::unique_ptr<IDisplay> mDisplay;
};
}  // namespace graphics