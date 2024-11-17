// GraphicsManager.hpp
#pragma once
#include "Model.hpp"
#include "Model2D.hpp"
#include "Model3D.hpp"
#include "IGraphicManager.hpp"
#include "CameraManager.hpp"
#include <atomic>
#include <mutex>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

namespace graphics {

class GraphicsManager : public IGraphicManager {
public:
    GraphicsManager();
    ~GraphicsManager() override;

    void SetConfigs(const GfxConfig& gfxConfigs) override;
    void Start() override;
    void SetTargetFramerate(unsigned int frameRate) override;
    std::shared_ptr<GraphicsContext> GetGraphicsContext() override;
    void Init() override;
    void Render() override;
    void SetCameraMng(std::shared_ptr<graphics::CameraManager> aCameraMng);
    // Drawing 2D methods
    void AddArc(const int& aLayerId, std::shared_ptr<Arc> aArc) override;
    void AddCircle(const int& aLayerId, std::shared_ptr<Circle> aCircle) override;
    void AddRectangle(const int& aLayerId, std::shared_ptr<Rectangle> aRectangle) override;
    void AddLine(const int& aLayerId, std::shared_ptr<Line> aLine) override;
    void AddPolyline(const int& aLayerId, std::shared_ptr<Polyline> aPolyline) override;
    void AddTriangle(const int& aLayerId, std::shared_ptr<Triangle> aTriangle) override;
    void AddPolygon(const int& aLayerId, std::shared_ptr<Polygon> aPolygon) override;
    void AddSphere(const int& aLayerId, std::shared_ptr<Sphere> aSphere) override;
    void AddCube(const int& aLayerId, std::shared_ptr<Cube> aCube) override;
    void AddLine3D(const int& aLayerId, std::shared_ptr<Line3D> aLine) override;

    void DrawLayer(const int& aLayerId) override;

    // Drawing 3D methods


    // clear methods
    void Clear(::Color aColor) override;


protected:
    void Run(); // Thread loop function

private:
    int mFrameRate;
    std::unique_ptr<std::thread> mThread;
    std::shared_ptr<GraphicsContext> mContext;
    std::shared_ptr<GfxConfig> mConfigs;
    std::unique_ptr<IDisplay> mDisplay;
    // Storage for drawing primitives, organized by layer
    std::unordered_map<int, std::vector<std::shared_ptr<Model>>> layers;
    std::shared_ptr<CameraManager> mCameraManager;
    // Synchronization
    std::mutex layersMutex;
};

} // namespace graphics
