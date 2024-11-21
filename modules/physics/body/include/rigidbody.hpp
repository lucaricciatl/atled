#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "Frame.hpp"
#include <array>

namespace physics{

class RigidBody {
private:
    Frame frame; // Position and orientation of the rigid body
    double mass; // Mass of the rigid body
    double inverseMass; // Inverse of mass (for calculations)

    // Inertia tensor and its inverse in body coordinates
    std::array<std::array<double, 3>, 3> inertiaTensor;
    std::array<std::array<double, 3>, 3> inverseInertiaTensor;

    // Accumulated forces and torques in world coordinates
    double fx, fy, fz; // Force accumulator
    double tx, ty, tz; // Torque accumulator

public:
    // Constructors
    RigidBody();
    RigidBody(const Frame& frame, double mass, const std::array<std::array<double, 3>, 3>& inertiaTensor);
    RigidBody(const RigidBody& other);

    // Destructor
    ~RigidBody();

    // Assignment operator
    RigidBody& operator=(const RigidBody& other);

    // Accessors
    Frame getFrame() const;
    double getMass() const;

    // Mutators
    void setFrame(const Frame& frame);
    void setMass(double mass);
    void setInertiaTensor(const std::array<std::array<double, 3>, 3>& inertiaTensor);

    // Helper methods
    void clearForces();
};

}

#endif // RIGIDBODY_HPP
