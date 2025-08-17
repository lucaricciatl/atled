#include "RigidBody.hpp"
#include "Vector3.hpp"
#include "MathUtils.hpp"
#include "Quaternion.hpp"

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
        mAccumulatedForce += math::Vector3(0, mAccumulatedForce.GetY() - mMass * g, 0);
    }
    math::Vector3 acceleration = mAccumulatedForce / mMass; // F = ma => a = F/m
    auto InvInertia = math::Pinv(mInertia);
    math::Matrix<float> momentumVector(1, 3);
    momentumVector(0,0) = mAccumulatedMomentum.GetX();
    momentumVector(0,1) = mAccumulatedMomentum.GetY();
    momentumVector(0,2) = mAccumulatedMomentum.GetZ();
    auto AngularAcceleration = momentumVector * InvInertia;
    math::Vector3 AngularVelocity( AngularAcceleration(0,0)* deltaTime, AngularAcceleration(0,1)* deltaTime , AngularAcceleration(0,2)* deltaTime) ;
    //mAngularVelocity += angularAcceleration * deltaTime;
    mFrame->translate(mVelocity.GetX() * deltaTime, mVelocity.GetY() * deltaTime,
                      mVelocity.GetZ() * deltaTime);  // Update position
    //auto orientation = mFrame->GetOrientation();
    //orientation.Rotate(AngularVelocity.GetX(),AngularVelocity.GetY(),AngularVelocity.GetZ(),deltaTime);
    //mFrame->SetOrientation(orientation);
    ClearForces(); // Clear forces for the next frame
}

} // namespace physics
