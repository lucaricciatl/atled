#pragma once

#include <memory>
#include "Frame.hpp"
#include "Vector3.hpp"
#include "body.hpp" 
namespace physics {



class RigidBody : public Body {
public:
    RigidBody();
    RigidBody(std::shared_ptr<Frame> frame);

    RigidBody(const RigidBody&) = delete;
    RigidBody& operator=(const RigidBody&) = delete;

    RigidBody(RigidBody&&) noexcept = default;
    RigidBody& operator=(RigidBody&&) noexcept = default;

    // Basic properties
    void SetStatic(bool isStatic);
    bool IsStatic() const;

    void SetUseGravity(bool useGravity);
    bool UsesGravity() const;

    void SetCollidable(bool isCollidable);
    bool IsCollidable() const;

    // Mass-related properties
    void SetMass(float mass);
    float GetMass() const;

    // Force and acceleration
    void ApplyForce(const math::Vector3& force);
    math::Vector3 GetAccumulatedForce() const;
    void ClearForces();

    // Update position based on forces and mass
    void UpdatePhysics(double deltaTime);

    void SetFrame(std::shared_ptr<Frame> aFrame) { mFrame = aFrame; };
    std::shared_ptr<Frame> GetFrame() const;


protected:
    std::shared_ptr<Frame> mFrame;

    bool mIsStatic;
    bool mUseGravity;
    bool mIsCollidable;

    float mMass;
    math::Vector3 mVelocity;
    math::Vector3 mAccumulatedForce;
};

} // namespace physics