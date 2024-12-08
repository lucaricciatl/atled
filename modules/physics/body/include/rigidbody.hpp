#pragma once

#include <memory>
#include "Frame.hpp"
#include "ICollider.hpp"
#include "raylib.hpp"

namespace physics {


class RigidBody {
public:
    RigidBody();
    RigidBody(std::shared_ptr<Frame> frame, std::shared_ptr<ICollider> collider);

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
    void ApplyForce(const raylib::Vector3& force);
    raylib::Vector3 GetAccumulatedForce() const;
    void ClearForces();

    // Update position based on forces and mass
    void UpdatePhysics(double deltaTime);

    void SetFrame(std::shared_ptr<Frame> aFrame) { mFrame = aFrame; };
    std::shared_ptr<Frame> GetFrame() const;
    std::shared_ptr<ICollider> GetCollider() const;

protected:
    std::shared_ptr<Frame> mFrame;
    std::shared_ptr<ICollider> mCollider;

    bool mIsStatic;
    bool mUseGravity;
    bool mIsCollidable;

    float mMass;
    raylib::Vector3 mVelocity;
    raylib::Vector3 mAccumulatedForce;
};

} // namespace physics