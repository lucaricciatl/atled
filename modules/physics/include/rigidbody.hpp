// RigidBody.hpp

#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "Frame.hpp"
#include <array>

namespace Math3D {

class RigidBody {
private:
    Frame frame;          // Position and orientation of the rigid body
    double mass;          // Mass of the rigid body
    double inverseMass;   // Inverse of mass (for calculations)

    // Inertia tensor and its inverse in body coordinates
    std::array<std::array<double, 3>, 3> inertiaTensor;
    std::array<std::array<double, 3>, 3> inverseInertiaTensor;

    // Linear velocity in world coordinates
    double vx, vy, vz;

    // Angular velocity in body coordinates
    double wx, wy, wz;

    // Accumulated forces and torques in world coordinates
    double fx, fy, fz;    // Force accumulator
    double tx, ty, tz;    // Torque accumulator

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
    void getVelocity(double& vx, double& vy, double& vz) const;
    void getAngularVelocity(double& wx, double& wy, double& wz) const;
    double getMass() const;

    // Mutators
    void setFrame(const Frame& frame);
    void setVelocity(double vx, double vy, double vz);
    void setAngularVelocity(double wx, double wy, double wz);
    void setMass(double mass);
    void setInertiaTensor(const std::array<std::array<double, 3>, 3>& inertiaTensor);

    // Physics methods
    void applyForce(double fx, double fy, double fz);
    void applyTorque(double tx, double ty, double tz);
    void integrate(double deltaTime);

    // Helper methods
    void clearForces();
};

} // namespace Math3D

#endif // RIGIDBODY_HPP
