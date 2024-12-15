#include "RigidBody.hpp"
#include "Vector3.hpp"

float g = 9.18;

namespace physics {

// Default constructor
RigidBody::RigidBody()
    : mFrame(nullptr), mIsStatic(false), mUseGravity(true),
      mIsCollidable(true), mMass(1.0f), mVelocity{0, 0, 0}, mAccumulatedForce{0, 0, 0}, Body() {}

// Constructor with parameters
RigidBody::RigidBody(std::shared_ptr<Frame> frame)
    : mFrame(std::move(frame)), mIsStatic(false), 
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
void RigidBody::ApplyForce(const math::Vector3& force) {
    mAccumulatedForce += force;
}

// Get the accumulated force
math::Vector3 RigidBody::GetAccumulatedForce() const {
    return mAccumulatedForce;
}

// Clear all accumulated forces
void RigidBody::ClearForces() {
    mAccumulatedForce = math::Vector3{0, 0, 0};
}

// Update the physics state
void RigidBody::UpdatePhysics(double deltaTime) {
    if (mIsStatic || deltaTime <= 0.0f) {
        return; // Static bodies don't move
    }
    if (mUseGravity) {
        mAccumulatedForce += math::Vector3(0,mAccumulatedForce.getY() - mMass * g,0);
    }
    math::Vector3 acceleration = mAccumulatedForce / mMass; // F = ma => a = F/m
    mVelocity += acceleration * deltaTime; // Update velocity
    mFrame->translate(mVelocity.getX() * deltaTime,mVelocity.getY() * deltaTime,mVelocity.getZ() * deltaTime); // Update position

    ClearForces(); // Clear forces for the next frame
}

} // namespace physics
