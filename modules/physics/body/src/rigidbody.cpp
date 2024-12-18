#include "RigidBody.hpp"
#include "Vector3.hpp"

float g = 9.18;

namespace physics {


// Constructor with parameters
RigidBody::RigidBody(std::shared_ptr<Frame> frame)
    : Body(frame) {}


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
