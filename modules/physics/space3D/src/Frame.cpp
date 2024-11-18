// Frame.cpp

#include "Frame.hpp"
#include <iostream>
#include <cmath>

namespace Math3D {

// Constructors
Frame::Frame() : x(0), y(0), z(0), orientation(1, 0, 0, 0) {}

Frame::Frame(double x, double y, double z, const Quaternion& orientation)
    : x(x), y(y), z(z), orientation(orientation.normalized()) {}

Frame::Frame(const Frame& other)
    : x(other.x), y(other.y), z(other.z), orientation(other.orientation) {}

// Destructor
Frame::~Frame() {}

// Assignment operator
Frame& Frame::operator=(const Frame& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
        orientation = other.orientation;
    }
    return *this;
}

// Accessors
double Frame::getX() const { return x; }
double Frame::getY() const { return y; }
double Frame::getZ() const { return z; }
Quaternion Frame::getOrientation() const { return orientation; }

// Mutators
void Frame::setPosition(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Frame::setOrientation(const Quaternion& orientation) {
    this->orientation = orientation.normalized();
}

// Frame operations
void Frame::translate(double dx, double dy, double dz) {
    x += dx;
    y += dy;
    z += dz;
}

void Frame::rotate(const Quaternion& rotation) {
    orientation = rotation.normalized() * orientation;
}

// Transformation methods
void Frame::transformPoint(double& px, double& py, double& pz) const {
    // Rotate point
    Quaternion point(0, px, py, pz);
    Quaternion rotated = orientation * point * orientation.conjugate();

    // Translate point
    px = rotated.getX() + x;
    py = rotated.getY() + y;
    pz = rotated.getZ() + z;
}

void Frame::inverseTransformPoint(double& px, double& py, double& pz) const {
    // Translate point
    double tx = px - x;
    double ty = py - y;
    double tz = pz - z;

    // Inverse rotate point
    Quaternion point(0, tx, ty, tz);
    Quaternion rotated = orientation.conjugate() * point * orientation;

    // Update point
    px = rotated.getX();
    py = rotated.getY();
    pz = rotated.getZ();
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Frame& frame) {
    os << "Position: (" << frame.x << ", " << frame.y << ", " << frame.z << "), "
       << "Orientation: " << frame.orientation;
    return os;
}

} // namespace Math3D
