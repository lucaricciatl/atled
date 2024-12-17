#include "Body.hpp"
#include "BoundingBox.hpp"

namespace physics {

Body::Body(std::shared_ptr<Frame> frame):
mFrame(frame), mIsStatic(false),
mUseGravity(true), mIsCollidable(true), mMass(1.0f), mVelocity{ 0, 0, 0 },
mAccumulatedForce{ 0, 0, 0 } {

}

// Set whether the rigid body is static
void Body::SetStatic(bool isStatic) {
    mIsStatic = isStatic;
}

// Check if the rigid body is static
bool Body::IsStatic() const {
    return mIsStatic;
}

// Set whether the rigid body uses gravity
void Body::SetUseGravity(bool useGravity) {
    mUseGravity = useGravity;
}

// Check if the rigid body uses gravity
bool Body::UsesGravity() const {
    return mUseGravity;
}

// Set whether the rigid body is collidable
void Body::SetCollidable(bool isCollidable) {
    mIsCollidable = isCollidable;
}

// Check if the rigid body is collidable
bool Body::IsCollidable() const {
    return mIsCollidable;
}

// Set the mass of the rigid body
void Body::SetMass(float mass) {
    mMass = (mass > 0.0f) ? mass : 1.0f; // Ensure mass is positive
}

// Get the mass of the rigid body
float Body::GetMass() const {
    return mMass;
}

// Apply a force to the rigid body
void Body::ApplyForce(const math::Vector3& force) {
    mAccumulatedForce += force;
}


// Clear all accumulated forces
void Body::ClearForces() {
    mAccumulatedForce = math::Vector3{ 0, 0, 0 };
}


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

    return math::BoundingBox(min + mFrame->GetVectorPosition(), max+ mFrame->GetVectorPosition());
}

void Body::Update(double deltaTime) {
    UpdatePhysics(deltaTime);
}
} // namespace physics
