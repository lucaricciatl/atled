#include "Body.hpp"
#include "BoundingBox.hpp"

namespace physics {

Body::~Body() = default;

void Body::SetMesh(std::shared_ptr<graphics::Mesh> aMesh) {
    mMesh = std::move(aMesh);
}

math::BoundingBox Body::GetBoundingBox() const {
    if (!mMesh) {
        throw std::runtime_error("Mesh not set for this body");
    }

    const auto& vertices = mMesh->GetVertices();
    if (vertices.empty()) {
        throw std::runtime_error("Mesh has no vertices");
    }

    // Initialize bounding box using the first vertex
    math::Vector3 min(vertices[0], vertices[1], vertices[2]);
    math::Vector3 max(vertices[0], vertices[1], vertices[2]);

    // Expand the bounding box to encompass all vertices
    for (size_t i = 3; i < vertices.size(); i += 3) { // Step by 3 (x, y, z)
        math::Vector3 vertex(vertices[i], vertices[i + 1], vertices[i + 2]);
        min = math::Vector3(
            std::min(min.getX(), vertex.getX()),
            std::min(min.getY(), vertex.getY()),
            std::min(min.getZ(), vertex.getZ())
        );
        max = math::Vector3(
            std::max(max.getX(), vertex.getX()),
            std::max(max.getY(), vertex.getY()),
            std::max(max.getZ(), vertex.getZ())
        );
    }

    return math::BoundingBox(min, max);
}

void Body::Update(double deltaTime) {
    UpdatePhysics(deltaTime);
}
} // namespace physics
