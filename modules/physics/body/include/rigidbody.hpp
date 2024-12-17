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


    // Update position based on forces and mass
    void UpdatePhysics(double deltaTime) override;



protected:


};

} // namespace physics