#include "Velocity.hpp"

namespace physics{

// Default constructor
Velocity::Velocity()
    : vx(0.0), vy(0.0), vz(0.0), wx(0.0), wy(0.0), wz(0.0) {}

// Parameterized constructor
Velocity::Velocity(double vx, double vy, double vz, double wx, double wy, double wz)
    : vx(vx), vy(vy), vz(vz), wx(wx), wy(wy), wz(wz) {}

// Get linear velocity
void Velocity::getLinearVelocity(double& x, double& y, double& z) const {
    x = vx;
    y = vy;
    z = vz;
}

// Get angular velocity
void Velocity::getAngularVelocity(double& x, double& y, double& z) const {
    x = wx;
    y = wy;
    z = wz;
}

// Set linear velocity
void Velocity::setLinearVelocity(double x, double y, double z) {
    vx = x;
    vy = y;
    vz = z;
}

// Set angular velocity
void Velocity::setAngularVelocity(double x, double y, double z) {
    wx = x;
    wy = y;
    wz = z;
}

// Clear velocities
void Velocity::clear() {
    vx = vy = vz = wx = wy = wz = 0.0;
}

}