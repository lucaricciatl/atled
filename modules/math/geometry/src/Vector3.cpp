// Vector3.cpp
#include "Vector3.hpp"

namespace math {

// Constructors
Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {}

// Getters
float Vector3::GetX() const { return x; }
float Vector3::GetY() const { return y; }
float Vector3::GetZ() const { return z; }

// Setters
void Vector3::SetX(float value) { x = value; }
void Vector3::SetY(float value) { y = value; }
void Vector3::SetZ(float value) { z = value; }

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
float Vector3::Dot(const Vector3& other) const { return x * other.x + y * other.y + z * other.z; }

// Cross product
Vector3 Vector3::Cross(const Vector3& other) const {
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

// Magnitude (length) of the vector
float Vector3::Magnitude() const { return std::sqrt(x * x + y * y + z * z); }

// Normalize the vector
Vector3 Vector3::Normalized() const {
    float mag = Magnitude();
    if (mag == 0.0f) {
        return *this;
    }
    return *this / mag;
}

// Print the vector (for debugging)
void Vector3::print() const {
    std::cout << "Vector3(" << x << ", " << y << ", " << z << ")\n";
}

} // namespace math
