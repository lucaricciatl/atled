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
#include "GraphicsConfig.hpp"
namespace graphics {


class IGraphicManager {
public:
    virtual ~IGraphicManager() = default;

    virtual void SetConfigs(const GraphicsConfig& gfxConfigs) = 0;
    virtual void Start() = 0;
    virtual void SetTargetFramerate(unsigned int frameRate) = 0;
    virtual std::shared_ptr<GraphicsContext> GetGraphicsContext() = 0;
    virtual void Init() = 0;
    virtual void Render() = 0;

    virtual void SetCameraMng(std::shared_ptr<CameraManager> aCameraMng) = 0 ;

    virtual void AddShape(const int& aLayerId, std::shared_ptr<Model> aShape) = 0;
    virtual void DrawLayer(const int& aLayerId) = 0;
    virtual void Clear(raylib::Color aColor) = 0;
};

} // namespace graphics
