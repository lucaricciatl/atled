#pragma once

#include <memory>
#include "Frame.hpp"
#include "Vector3.hpp"
#include "Mesh.hpp"
#include "BoundingBox.hpp" // Include your BoundingBox class

namespace physics {

class Body {
public:
    Body() = default;
    virtual ~Body();

    void SetMesh(std::shared_ptr<graphics::Mesh> aMesh);
    void Update(double deltaTime);
    virtual void UpdatePhysics(double deltaTime)=0;
    // Compute and return the bounding box of the body
    math::BoundingBox GetBoundingBox() const;

    std::shared_ptr<graphics::Mesh> mMesh;
};

} // namespace physics
