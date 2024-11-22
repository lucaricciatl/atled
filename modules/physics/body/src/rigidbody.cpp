#include "RigidBody.hpp"
#include <stdexcept>

namespace physics{

// Default constructor
RigidBody::RigidBody()
    : frame(), mass(1.0), inverseMass(1.0),
      fx(0.0), fy(0.0), fz(0.0), tx(0.0), ty(0.0), tz(0.0) {
    // Default inertia tensor for a unit sphere
    inertiaTensor = {{
        {2.0 / 5.0 * mass, 0.0, 0.0},
        {0.0, 2.0 / 5.0 * mass, 0.0},
        {0.0, 0.0, 2.0 / 5.0 * mass}
    }};
    inverseInertiaTensor = inertiaTensor; // Placeholder: Normally you calculate the inverse
}

// Parameterized constructor
RigidBody::RigidBody(const Frame& frame, double mass, const std::array<std::array<double, 3>, 3>& inertiaTensor)
    : frame(frame), mass(mass), inverseMass(mass != 0 ? 1.0 / mass : 0.0),
      fx(0.0), fy(0.0), fz(0.0), tx(0.0), ty(0.0), tz(0.0),
      inertiaTensor(inertiaTensor) {
    // Calculate inverse inertia tensor
    if (mass == 0.0) {
        throw std::invalid_argument("Mass cannot be zero.");
    }
    inverseInertiaTensor = inertiaTensor; // Placeholder: Normally calculate the actual inverse
}

// Copy constructor
RigidBody::RigidBody(const RigidBody& other)
    : frame(other.frame), mass(other.mass), inverseMass(other.inverseMass),
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

double RigidBody::getMass() const {
    return mass;
}

// Mutators
void RigidBody::setFrame(const Frame& frame) {
    this->frame = frame;
}

void RigidBody::setMass(double mass) {
    if (mass <= 0.0) {
        throw std::invalid_argument("Mass must be positive.");
    }
    this->mass = mass;
    this->inverseMass = 1.0 / mass;

    // Update inertia tensor accordingly (assuming uniform scaling)
    for (int i = 0; i < 3; ++i) {
        inertiaTensor[i][i] = (2.0 / 5.0) * mass;
    }
    inverseInertiaTensor = inertiaTensor; // Placeholder: Normally calculate the actual inverse
}

void RigidBody::setInertiaTensor(const std::array<std::array<double, 3>, 3>& inertiaTensor) {
    this->inertiaTensor = inertiaTensor;
    inverseInertiaTensor = inertiaTensor; // Placeholder: Normally calculate the actual inverse
}

// Helper methods
void RigidBody::clearForces() {
    fx = 0.0;
    fy = 0.0;
    fz = 0.0;
    tx = 0.0;
    ty = 0.0;
    tz = 0.0;
}

} // namespace physics