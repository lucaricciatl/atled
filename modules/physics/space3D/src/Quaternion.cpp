// Quaternion.cpp

#include "Quaternion.hpp"
#include <cmath>
#include <stdexcept>


namespace math{
// Constructors
Quaternion::Quaternion() : w(0), x(0), y(0), z(0) {}

Quaternion::Quaternion(double w, double x, double y, double z)
    : w(w), x(x), y(y), z(z) {}

Quaternion::Quaternion(const Quaternion& q)
    : w(q.w), x(q.x), y(q.y), z(q.z) {}

// Destructor
Quaternion::~Quaternion() {}

// Assignment operator
Quaternion& Quaternion::operator=(const Quaternion& q) {
    if (this != &q) {
        w = q.w;
        x = q.x;
        y = q.y;
        z = q.z;
    }
    return *this;
}

// Accessors (Getters)
double Quaternion::getW() const { return w; }
double Quaternion::getX() const { return x; }
double Quaternion::getY() const { return y; }
double Quaternion::getZ() const { return z; }

// Mutators (Setters)
void Quaternion::setW(double w) { this->w = w; }
void Quaternion::setX(double x) { this->x = x; }
void Quaternion::setY(double y) { this->y = y; }
void Quaternion::setZ(double z) { this->z = z; }

math::Vector3 Quaternion::rotateVector(const math::Vector3& v) const {
    // This uses the formula: v' = q * v * q^-1
    Quaternion vectorQuat(0, v.getX(), v.getY(), v.getZ());
    Quaternion result = (*this) * vectorQuat * this->inverse();
    return math::Vector3(result.x, result.y, result.z);
}

// Quaternion operations
double Quaternion::magnitude() const {
    return std::sqrt(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::normalized() const {
    double mag = magnitude();
    if (mag == 0) {
        throw std::runtime_error("Cannot normalize a quaternion with zero magnitude");
    }
    return Quaternion(w / mag, x / mag, y / mag, z / mag);
}

Quaternion Quaternion::conjugate() const {
    return Quaternion(w, -x, -y, -z);
}

Quaternion Quaternion::inverse() const {
    double mag_sq = w * w + x * x + y * y + z * z;
    if (mag_sq == 0) {
        throw std::runtime_error("Cannot invert a quaternion with zero magnitude");
    }
    Quaternion conj = conjugate();
    return Quaternion(conj.w / mag_sq, conj.x / mag_sq, conj.y / mag_sq, conj.z / mag_sq);
}

// Operator overloading
Quaternion Quaternion::operator+(const Quaternion& q) const {
    return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}

Quaternion Quaternion::operator-(const Quaternion& q) const {
    return Quaternion(w - q.w, x - q.x, y - q.y, z - q.z);
}

Quaternion Quaternion::operator*(const Quaternion& q) const {
    double nw = w * q.w - x * q.x - y * q.y - z * q.z;
    double nx = w * q.x + x * q.w + y * q.z - z * q.y;
    double ny = w * q.y - x * q.z + y * q.w + z * q.x;
    double nz = w * q.z + x * q.y - y * q.x + z * q.w;
    return Quaternion(nw, nx, ny, nz);
}

Quaternion Quaternion::operator*(double scalar) const {
    return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
}

Quaternion Quaternion::operator/(double scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Quaternion(w / scalar, x / scalar, y / scalar, z / scalar);
}

Quaternion Quaternion::operator/(const Quaternion& q) const {
    return (*this) * q.inverse();
}

bool Quaternion::operator==(const Quaternion& q) const {
    return w == q.w && x == q.x && y == q.y && z == q.z;
}

bool Quaternion::operator!=(const Quaternion& q) const {
    return !(*this == q);
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Quaternion& q) {
    os << "(" << q.w << ", " << q.x << "i, " << q.y << "j, " << q.z << "k)";
    return os;
}

Quaternion Quaternion::fromAxisAngle(double angle, const double axis[3]) {
    double halfAngle = angle * 0.5;
    double sinHalfAngle = std::sin(halfAngle);

    return Quaternion(
        std::cos(halfAngle),
        axis[0] * sinHalfAngle,
        axis[1] * sinHalfAngle,
        axis[2] * sinHalfAngle
    );
}

} 