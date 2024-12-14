// Vector3.cpp
#include "Vector3.hpp"

namespace math {

// Constructors
Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {}

// Getters
float Vector3::getX() const { return x; }
float Vector3::getY() const { return y; }
float Vector3::getZ() const { return z; }

// Setters
void Vector3::setX(float value) { x = value; }
void Vector3::setY(float value) { y = value; }
void Vector3::setZ(float value) { z = value; }

// Vector addition
Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

// In-place Vector addition
Vector3& Vector3::operator+=(const Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

// Vector subtraction
Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

// Scalar multiplication
Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

// Scalar division
Vector3 Vector3::operator/(float scalar) const {
    if (scalar == 0.0f) {
        throw std::runtime_error("Division by zero");
    }
    return Vector3(x / scalar, y / scalar, z / scalar);
}

// Dot product
float Vector3::dot(const Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// Cross product
Vector3 Vector3::cross(const Vector3& other) const {
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

// Magnitude (length) of the vector
float Vector3::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Normalize the vector
Vector3 Vector3::normalized() const {
    float mag = magnitude();
    if (mag == 0.0f) {
        throw std::runtime_error("Cannot normalize zero-length vector");
    }
    return *this / mag;
}

// Print the vector (for debugging)
void Vector3::print() const {
    std::cout << "Vector3(" << x << ", " << y << ", " << z << ")\n";
}

} // namespace math
