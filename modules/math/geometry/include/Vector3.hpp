#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>
#include <cmath>
#include <stdexcept>

namespace math{

class Vector3 {
private:
    float x, y, z;

public:
    // Constructors
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(const Vector3& other);

    // Getters
    float getX() const;
    float getY() const;
    float getZ() const;

    // Setters
    void setX(float value);
    void setY(float value);
    void setZ(float value);

    // Vector addition
    Vector3 operator+(const Vector3& other) const;

    // Vector subtraction
    Vector3 operator-(const Vector3& other) const;

    // Scalar multiplication
    Vector3 operator*(float scalar) const;

    // Scalar division
    Vector3 operator/(float scalar) const;

    // Dot product
    float dot(const Vector3& other) const;

    // Cross product
    Vector3 cross(const Vector3& other) const;

    // Magnitude (length) of the vector
    float magnitude() const;

    // Normalize the vector
    Vector3 normalized() const;

    // Print the vector (for debugging)
    void print() const;
};

}

#endif // VECTOR3_HPP
