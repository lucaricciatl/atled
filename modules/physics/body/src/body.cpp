#include "Body.hpp"
#include "BoundingBox.hpp"

namespace physics {

Body::Body(std::shared_ptr<Frame> frame)
    : mFrame(frame),
      mIsStatic(false),
      mUseGravity(true),
      mIsCollidable(true),
      mMass(1.0f),
      mVelocity{0, 0, 0},
      mAccumulatedForce{0, 0, 0},
      mMesh(nullptr) {}

// Set whether the rigid body is static
void Body::SetStatic(bool isStatic) { mIsStatic = isStatic; }

// Check if the rigid body is static
bool Body::IsStatic() const { return mIsStatic; }

// Set whether the rigid body uses gravity
void Body::SetUseGravity(bool useGravity) { mUseGravity = useGravity; }

// Check if the rigid body uses gravity
bool Body::UsesGravity() const { return mUseGravity; }

// Set whether the rigid body is collidable
void Body::SetCollidable(bool isCollidable) { mIsCollidable = isCollidable; }

// Check if the rigid body is collidable
bool Body::IsCollidable() const { return mIsCollidable; }

// Set the mass of the rigid body
void Body::SetMass(float mass) {
    mMass = (mass > 0.0f) ? mass : 1.0f;  // Ensure mass is positive
}

// Get the mass of the rigid body
float Body::GetMass() const { return mMass; }

std::shared_ptr<Frame> Body::GetFrame() const { return mFrame; };

void Body::ApplyForceToPoint(const math::Vector3& force, const Position& position) { 
    mAccumulatedForce += force; 
};

void Body::ApplyMomentum(const math::Vector3& momentum) {}

void Body::ApplyMomentum(const math::Vector3& axis, const float module) {}

// Clear all accumulated forces
void Body::ClearForces() {
    mAccumulatedForce = math::Vector3{ 0, 0, 0 };
}


Body::~Body() = default;

void Body::SetMesh(std::shared_ptr<graphics::Mesh> aMesh) {
    mMesh = aMesh;
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
        min = math::Vector3(std::min(min.GetX(), vertex.GetX()), std::min(min.GetY(), vertex.GetY()),
                            std::min(min.GetZ(), vertex.GetZ()));
        max = math::Vector3(std::max(max.GetX(), vertex.GetX()), std::max(max.GetY(), vertex.GetY()),
                            std::max(max.GetZ(), vertex.GetZ()));
    }
    auto bbox = math::BoundingBox(min + mFrame->GetVectorPosition(), max + mFrame->GetVectorPosition());
    return bbox;
}

void Body::Update(double deltaTime) {
    UpdatePhysics(deltaTime);
}
} // namespace physics
