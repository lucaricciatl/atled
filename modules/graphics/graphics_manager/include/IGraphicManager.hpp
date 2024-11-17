// IGraphicsManager.hpp
#pragma once

#include <memory>
#include <vector>
#include "GraphicsContext.hpp"
#include "CameraManager.hpp"
#include "IDisplay.hpp"
#include "Sphere.hpp"
#include "Cube.hpp"
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

    // Drawing methods
    virtual void AddArc(const int& aLayerId, std::shared_ptr<Arc> aArc) = 0;
    virtual void AddCircle(const int& aLayerId, std::shared_ptr<Circle> aCircle) = 0;
    virtual void AddRectangle(const int& aLayerId, std::shared_ptr<Rectangle> aRectangle) = 0;
    virtual void AddLine(const int& aLayerId, std::shared_ptr<Line> aLine) = 0;
    virtual void AddPolyline(const int& aLayerId, std::shared_ptr<Polyline> aPolyline) = 0;
    virtual void AddTriangle(const int& aLayerId, std::shared_ptr<Triangle> aTriangle) = 0;
    virtual void AddPolygon(const int& aLayerId, std::shared_ptr<Polygon> aPolygon) = 0;
    virtual void AddSphere(const int& aLayerId, std::shared_ptr<Sphere> aSphere) = 0;
    virtual void AddCube(const int& aLayerId, std::shared_ptr<Cube> aCube) = 0;
    virtual void AddLine3D(const int& aLayerId, std::shared_ptr<Line3D> aLine) = 0;
    virtual void DrawLayer(const int& aLayerId) = 0;
    virtual void Clear(::Color aColor) = 0;
};

} // namespace graphics
