#pragma once

#include <memory>
#include "Frame.hpp"
#include "Vector3.hpp"
#include "Mesh.hpp"

namespace physics {

class Body {
public:
    Body() = default;
    virtual ~Body();

    void SetMesh(std::shared_ptr<graphics::Mesh> aMesh);

    std::shared_ptr<graphics::Mesh> mMesh;
};

} // namespace physics