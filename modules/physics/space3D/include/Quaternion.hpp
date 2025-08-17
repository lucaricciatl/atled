// Quaternion.hpp

#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include <iostream>
#include <Vector3.hpp>
#include <Matrix.hpp>

namespace math{

class Quaternion {
private:
    double w, x, y, z;

public:
    // Constructors
    Quaternion();
    Quaternion(double w, double x, double y, double z);
    Quaternion(const Quaternion& q);

    // Destructor
    ~Quaternion();

    // Assignment operator
    Quaternion& operator=(const Quaternion& q);

    // Accessors (Getters)
    double GetW() const;
    double GetX() const;
    double GetY() const;
    double GetZ() const;

    // Mutators (Setters)
    void SetW(double w);
    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);

    math::Vector3 RotateVector(const math::Vector3& v) const;

    // Quaternion operations
    double Magnitude() const;
    Quaternion Normalized() const;
    Quaternion Conjugate() const;
    Quaternion Inverse() const;

    // Operator overloading
    Quaternion operator+(const Quaternion& q) const;
    Quaternion operator-(const Quaternion& q) const;
    Quaternion operator*(const Quaternion& q) const;
    Quaternion operator*(double scalar) const;
    Quaternion operator/(double scalar) const;
    Quaternion operator/(const Quaternion& q) const;

    bool operator==(const Quaternion& q) const;
    bool operator!=(const Quaternion& q) const;

    // Friend functions for stream insertion
    friend std::ostream& operator<<(std::ostream& os, const Quaternion& q);

    static Quaternion FromAxisAngle(double angle, const double axis[3]);
    void Rotate(double wx, double wy, double wz, double dt);
};

} // namespace physics
#endif // QUATERNION_HPP
