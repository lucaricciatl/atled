// IGraphicsManager.hpp
#pragma once

#include <memory>
#include <vector>
#include "GraphicsContext.hpp"
#include "CameraManager.hpp"
#include "IDisplay.hpp"
#include "Sphere.hpp"
#include "Cube.hpp"
#include "Capsule.hpp"
#include "Cylinder.hpp"
#include "Plane.hpp"
#include "Line3D.hpp"

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

class IGraphicManager {
public:
    virtual ~IGraphicManager() = default;

    virtual void SetConfigs(const GfxConfig& gfxConfigs) = 0;
    virtual void Start() = 0;
    virtual void SetTargetFramerate(unsigned int frameRate) = 0;
    virtual std::shared_ptr<GraphicsContext> GetGraphicsContext() = 0;
    virtual void Init() = 0;
    virtual void Render() = 0;

    virtual void SetCameraMng(std::shared_ptr<CameraManager> aCameraMng) = 0 ;

    virtual void AddShape(const int& aLayerId, std::shared_ptr<Model> aShape) = 0;
    virtual void DrawLayer(const int& aLayerId) = 0;
    virtual void Clear(::Color aColor) = 0;
};

} // namespace graphics
