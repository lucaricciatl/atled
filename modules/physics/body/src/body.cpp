#include "Body.hpp"

namespace physics {

Body::~Body() = default;

void Body::SetMesh(std::shared_ptr<graphics::Mesh> aMesh) {
    mMesh = aMesh;
}

} // namespace physics
