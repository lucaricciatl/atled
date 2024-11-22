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

    void SetConfigs(const GraphicsConfig& gfxConfigs) override;
    void Start() override;
    void SetTargetFramerate(unsigned int frameRate) override;
    std::shared_ptr<GraphicsContext> GetGraphicsContext() override;
    void Init() override;
    void Render() override;
    void SetCameraMng(std::shared_ptr<graphics::CameraManager> aCameraMng);
    void AddShape(const int& aLayerId, std::shared_ptr<Model> aShape);

    void DrawLayer(const int& aLayerId) override;

    // Drawing 3D methods


    // clear methods
    void Clear(raylib::Color aColor) override;


protected:
    void Run(); // Thread loop function

private:
    int mFrameRate = 60;
    std::unique_ptr<std::thread> mThread;
    std::shared_ptr<GraphicsContext> mContext;
    std::shared_ptr<GraphicsConfig> mConfigs;
    std::unique_ptr<IDisplay> mDisplay;
    // Storage for drawing primitives, organized by layer
    std::unordered_map<int, std::vector<std::shared_ptr<Model>>> layers;
    std::shared_ptr<CameraManager> mCameraManager;
    // Synchronization
    std::mutex layersMutex;
};

} // namespace graphics
