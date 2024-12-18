// Vector3.hpp
#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>

namespace math {

class Vector3 {
public:
    // Constructors
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(const Vector3& other);

    // Destructor
    ~Vector3() = default;

    // Getters
    float getX() const;
    float getY() const;
    float getZ() const;

    // Setters
    void setX(float value);
    void setY(float value);
    void setZ(float value);

    // Operator Overloads
    Vector3 operator+(const Vector3& other) const;
    Vector3& operator+=(const Vector3& other); // Added operator+=
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(float scalar) const;
    Vector3 operator/(float scalar) const;
    Vector3& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    // Unary negation operator
    Vector3 operator-() const {
        return Vector3(-x, -y, -z);
    }
    // Dot and Cross Products
    float dot(const Vector3& other) const;
    Vector3 cross(const Vector3& other) const;

    // Magnitude and Normalization
    float magnitude() const;
    Vector3 normalized() const;

    // Utility
    void print() const;

    bool isZero(float epsilon = 1e-6f) const {
        return (std::fabs(x) < epsilon &&
            std::fabs(y) < epsilon &&
            std::fabs(z) < epsilon);
    }
private:
    float x;
    float y;
    float z;
};

} // namespace math

#endif // VECTOR3_HPP
