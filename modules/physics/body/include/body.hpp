#pragma once

#include <memory>
#include "Frame.hpp"
#include "Vector3.hpp"
#include "Matrix.hpp"
#include "Mesh.hpp"
#include "BoundingBox.hpp" // Include your BoundingBox class

namespace physics {

class Body {
public:
    Body(std::shared_ptr<Frame> frame);
    virtual ~Body();
    void Update(double deltaTime);
    virtual void UpdatePhysics(double deltaTime) = 0;
    void SetMesh(std::shared_ptr<graphics::Mesh> aMesh);

    void ApplyForceToPoint(const math::Vector3& force, const Position& position = Position(0.0f, 0.0f, 0.0f));
    void ApplyMomentum(const math::Vector3& momentum);
    void ApplyMomentum(const math::Vector3& axis, const float module);

    // Compute and return the bounding box of the body
    math::BoundingBox GetBoundingBox() const;
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

    math::Vector3 GetAccumulatedForce() const { return mAccumulatedForce; };
    void ClearForces();

    void SetFrame(std::shared_ptr<Frame> aFrame) { mFrame = aFrame; };
    std::shared_ptr<Frame> GetFrame() const;
    std::shared_ptr<graphics::Mesh> mMesh;

    std::shared_ptr<Frame> mFrame;
    math::Vector3 mAccumulatedForce;
    bool mIsStatic;
    bool mUseGravity;
    bool mIsCollidable;
    math::Vector3 mAccumulatedMomentum;
    math::Vector3 mCenterOfMass;
    float mMass;
    math::Vector3 mVelocity;
    math::Vector3 mAngularVelocity;
    math::Matrix<float> mInertia;
};

} // namespace physics
