#include "RigidBody.hpp"


float g = 9.18;

namespace physics {

// Default constructor
RigidBody::RigidBody()
    : mFrame(nullptr), mCollider(nullptr), mIsStatic(false), mUseGravity(true),
      mIsCollidable(true), mMass(1.0f), mVelocity{0, 0, 0}, mAccumulatedForce{0, 0, 0} {}

// Constructor with parameters
RigidBody::RigidBody(std::shared_ptr<Frame> frame, std::shared_ptr<ICollider> collider)
    : mFrame(std::move(frame)), mCollider(std::move(collider)), mIsStatic(false), 
      mUseGravity(true), mIsCollidable(true), mMass(1.0f), mVelocity{0, 0, 0}, 
      mAccumulatedForce{0, 0, 0} {}

// Set whether the rigid body is static
void RigidBody::SetStatic(bool isStatic) {
    mIsStatic = isStatic;
}

// Check if the rigid body is static
bool RigidBody::IsStatic() const {
    return mIsStatic;
}

// Set whether the rigid body uses gravity
void RigidBody::SetUseGravity(bool useGravity) {
    mUseGravity = useGravity;
}

// Check if the rigid body uses gravity
bool RigidBody::UsesGravity() const {
    return mUseGravity;
}

// Set whether the rigid body is collidable
void RigidBody::SetCollidable(bool isCollidable) {
    mIsCollidable = isCollidable;
}

// Check if the rigid body is collidable
bool RigidBody::IsCollidable() const {
    return mIsCollidable;
}

// Set the mass of the rigid body
void RigidBody::SetMass(float mass) {
    mMass = (mass > 0.0f) ? mass : 1.0f; // Ensure mass is positive
}

// Get the mass of the rigid body
float RigidBody::GetMass() const {
    return mMass;
}

// Apply a force to the rigid body
void RigidBody::ApplyForce(const raylib::Vector3& force) {
    mAccumulatedForce.x += force.x;
    mAccumulatedForce.y += force.y;
    mAccumulatedForce.z += force.z;
}

// Get the accumulated force
raylib::Vector3 RigidBody::GetAccumulatedForce() const {
    return mAccumulatedForce;
}

// Clear all accumulated forces
void RigidBody::ClearForces() {
    mAccumulatedForce = raylib::Vector3{0, 0, 0};
}

// Update the physics state
void RigidBody::UpdatePhysics(double deltaTime) {
    if (mIsStatic || deltaTime <= 0.0f) {
        return; // Static bodies don't move
    }
    if (mUseGravity) {
        mAccumulatedForce.y -= mMass * g;
    }
    raylib::Vector3 acceleration = {mAccumulatedForce.x * (1.0f / mMass),mAccumulatedForce.y * (1.0f / mMass),mAccumulatedForce.z * (1.0f / mMass)}; // F = ma => a = F/m
    mVelocity.x += acceleration.x * deltaTime; // Update velocity
    mVelocity.y += acceleration.y * deltaTime; // Update velocity
    mVelocity.z += acceleration.z * deltaTime; // Update velocity
    mFrame->translate(mVelocity.x * deltaTime,mVelocity.y * deltaTime,mVelocity.z * deltaTime); // Update position

    ClearForces(); // Clear forces for the next frame
}

// Get the associated collider
std::shared_ptr<ICollider> RigidBody::GetCollider() const {
    return mCollider;
}

} // namespace physics
