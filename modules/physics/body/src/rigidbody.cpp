// RigidBody.cpp

#include "RigidBody.hpp"
#include <iostream>
#include <cmath>

namespace Math3D {

// Helper functions for matrix operations
namespace {

    // Multiply a 3x3 matrix by a 3-element vector
    void multiplyMatrixVector(const std::array<std::array<double, 3>, 3>& matrix,
                              const double vec[3],
                              double result[3]) {
        for (int i = 0; i < 3; ++i) {
            result[i] = matrix[i][0] * vec[0] +
                        matrix[i][1] * vec[1] +
                        matrix[i][2] * vec[2];
        }
    }

    // Invert a symmetric 3x3 matrix (assuming it's positive definite)
    std::array<std::array<double, 3>, 3> invertSymmetricMatrix(const std::array<std::array<double, 3>, 3>& m) {
        double det = m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]) -
                     m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0]) +
                     m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);

        if (det == 0.0) {
            throw std::runtime_error("Inertia tensor is singular and cannot be inverted.");
        }

        double invDet = 1.0 / det;

        std::array<std::array<double, 3>, 3> inv;

        inv[0][0] =  invDet * (m[1][1]*m[2][2] - m[1][2]*m[2][1]);
        inv[0][1] = -invDet * (m[0][1]*m[2][2] - m[0][2]*m[2][1]);
        inv[0][2] =  invDet * (m[0][1]*m[1][2] - m[0][2]*m[1][1]);

        inv[1][0] = -invDet * (m[1][0]*m[2][2] - m[1][2]*m[2][0]);
        inv[1][1] =  invDet * (m[0][0]*m[2][2] - m[0][2]*m[2][0]);
        inv[1][2] = -invDet * (m[0][0]*m[1][2] - m[0][2]*m[1][0]);

        inv[2][0] =  invDet * (m[1][0]*m[2][1] - m[1][1]*m[2][0]);
        inv[2][1] = -invDet * (m[0][0]*m[2][1] - m[0][1]*m[2][0]);
        inv[2][2] =  invDet * (m[0][0]*m[1][1] - m[0][1]*m[1][0]);

        return inv;
    }
}

// Constructors
RigidBody::RigidBody()
    : frame(), mass(1.0), inverseMass(1.0),
      vx(0), vy(0), vz(0),
      wx(0), wy(0), wz(0),
      fx(0), fy(0), fz(0),
      tx(0), ty(0), tz(0) {
    // Default inertia tensor (unit sphere)
    inertiaTensor = { {
        {2.0/5.0 * mass, 0.0, 0.0},
        {0.0, 2.0/5.0 * mass, 0.0},
        {0.0, 0.0, 2.0/5.0 * mass}
    } };
    inverseInertiaTensor = invertSymmetricMatrix(inertiaTensor);
}

RigidBody::RigidBody(const Frame& frame, double mass, const std::array<std::array<double, 3>, 3>& inertiaTensor)
    : frame(frame), mass(mass), inverseMass(mass != 0 ? 1.0 / mass : 0.0),
      vx(0), vy(0), vz(0),
      wx(0), wy(0), wz(0),
      fx(0), fy(0), fz(0),
      tx(0), ty(0), tz(0),
      inertiaTensor(inertiaTensor),
      inverseInertiaTensor(invertSymmetricMatrix(inertiaTensor)) {
}

// Copy constructor
RigidBody::RigidBody(const RigidBody& other)
    : frame(other.frame), mass(other.mass), inverseMass(other.inverseMass),
      vx(other.vx), vy(other.vy), vz(other.vz),
      wx(other.wx), wy(other.wy), wz(other.wz),
      fx(other.fx), fy(other.fy), fz(other.fz),
      tx(other.tx), ty(other.ty), tz(other.tz),
      inertiaTensor(other.inertiaTensor),
      inverseInertiaTensor(other.inverseInertiaTensor) {
}

// Destructor
RigidBody::~RigidBody() {}

// Assignment operator
RigidBody& RigidBody::operator=(const RigidBody& other) {
    if (this != &other) {
        frame = other.frame;
        mass = other.mass;
        inverseMass = other.inverseMass;
        vx = other.vx;
        vy = other.vy;
        vz = other.vz;
        wx = other.wx;
        wy = other.wy;
        wz = other.wz;
        fx = other.fx;
        fy = other.fy;
        fz = other.fz;
        tx = other.tx;
        ty = other.ty;
        tz = other.tz;
        inertiaTensor = other.inertiaTensor;
        inverseInertiaTensor = other.inverseInertiaTensor;
    }
    return *this;
}

// Accessors
Frame RigidBody::getFrame() const {
    return frame;
}

void RigidBody::getVelocity(double& outVx, double& outVy, double& outVz) const {
    outVx = vx;
    outVy = vy;
    outVz = vz;
}

void RigidBody::getAngularVelocity(double& outWx, double& outWy, double& outWz) const {
    outWx = wx;
    outWy = wy;
    outWz = wz;
}

double RigidBody::getMass() const {
    return mass;
}

// Mutators
void RigidBody::setFrame(const Frame& frame) {
    this->frame = frame;
}

void RigidBody::setVelocity(double vx, double vy, double vz) {
    this->vx = vx;
    this->vy = vy;
    this->vz = vz;
}

void RigidBody::setAngularVelocity(double wx, double wy, double wz) {
    this->wx = wx;
    this->wy = wy;
    this->wz = wz;
}

void RigidBody::setMass(double mass) {
    this->mass = mass;
    this->inverseMass = (mass != 0) ? 1.0 / mass : 0.0;
    // Update inertia tensor accordingly (assuming uniform scaling)
    for (int i = 0; i < 3; ++i) {
        inertiaTensor[i][i] = (2.0 / 5.0) * mass;
    }
    inverseInertiaTensor = invertSymmetricMatrix(inertiaTensor);
}

void RigidBody::setInertiaTensor(const std::array<std::array<double, 3>, 3>& inertiaTensor) {
    this->inertiaTensor = inertiaTensor;
    this->inverseInertiaTensor = invertSymmetricMatrix(inertiaTensor);
}

// Physics methods
void RigidBody::applyForce(double fx, double fy, double fz) {
    this->fx += fx;
    this->fy += fy;
    this->fz += fz;
}

void RigidBody::applyTorque(double tx, double ty, double tz) {
    this->tx += tx;
    this->ty += ty;
    this->tz += tz;
}

void RigidBody::integrate(double deltaTime) {
    if (inverseMass == 0.0) {
        // Infinite mass object, does not move
        return;
    }

    // **Linear Dynamics**

    // Update linear velocity (semi-implicit Euler)
    vx += (fx * inverseMass) * deltaTime;
    vy += (fy * inverseMass) * deltaTime;
    vz += (fz * inverseMass) * deltaTime;

    // Update position
    frame.translate(vx * deltaTime, vy * deltaTime, vz * deltaTime);

    // **Angular Dynamics**

    // Convert angular velocity to world coordinates
    double omegaWorld[3];
    Quaternion orientation = frame.getOrientation();
    double qx = orientation.getX();
    double qy = orientation.getY();
    double qz = orientation.getZ();
    double qw = orientation.getW();

    // Rotate angular velocity to world coordinates
    double wxWorld = wx * (1 - 2 * (qy*qy + qz*qz)) + wy * (2 * (qx*qy - qw*qz)) + wz * (2 * (qx*qz + qw*qy));
    double wyWorld = wx * (2 * (qx*qy + qw*qz)) + wy * (1 - 2 * (qx*qx + qz*qz)) + wz * (2 * (qy*qz - qw*qx));
    double wzWorld = wx * (2 * (qx*qz - qw*qy)) + wy * (2 * (qy*qz + qw*qx)) + wz * (1 - 2 * (qx*qx + qy*qy));

    // Update angular momentum (L = I * omega)
    double torqueWorld[3] = { tx, ty, tz };
    double angAccWorld[3];
    multiplyMatrixVector(inverseInertiaTensor, torqueWorld, angAccWorld);

    // Update angular velocity (semi-implicit Euler)
    wxWorld += angAccWorld[0] * deltaTime;
    wyWorld += angAccWorld[1] * deltaTime;
    wzWorld += angAccWorld[2] * deltaTime;

    // Update orientation quaternion
    double halfDeltaTime = 0.5 * deltaTime;
    Quaternion deltaOrientation(
        0,
        wxWorld * halfDeltaTime,
        wyWorld * halfDeltaTime,
        wzWorld * halfDeltaTime
    );

    Quaternion newOrientation = orientation + deltaOrientation * orientation;
    frame.setOrientation(newOrientation.normalized()); // Normalize to prevent drift

    // Convert angular velocity back to body coordinates
    double inverseOrientationX = -qx;
    double inverseOrientationY = -qy;
    double inverseOrientationZ = -qz;
    double inverseOrientationW = qw;

    Quaternion omegaWorldQuat(0, wxWorld, wyWorld, wzWorld);
    Quaternion omegaBodyQuat = (orientation.conjugate() * omegaWorldQuat * orientation);

    wx = omegaBodyQuat.getX();
    wy = omegaBodyQuat.getY();
    wz = omegaBodyQuat.getZ();

    // Clear forces and torques for the next integration step
    clearForces();
}

// Helper methods
void RigidBody::clearForces() {
    fx = fy = fz = 0.0;
    tx = ty = tz = 0.0;
}

} // namespace Math3D
