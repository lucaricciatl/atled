// Quaternion.hpp

#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include <iostream>
#include <Vector3.hpp>
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
    double getW() const;
    double getX() const;
    double getY() const;
    double getZ() const;

    // Mutators (Setters)
    void setW(double w);
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    math::Vector3 rotateVector(const math::Vector3& v) const;

    // Quaternion operations
    double magnitude() const;
    Quaternion normalized() const;
    Quaternion conjugate() const;
    Quaternion inverse() const;

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

    static Quaternion fromAxisAngle(double angle, const double axis[3]);
};

} // namespace physics
#endif // QUATERNION_HPP
