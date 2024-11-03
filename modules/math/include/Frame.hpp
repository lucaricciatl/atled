// Frame.hpp

#ifndef FRAME_HPP
#define FRAME_HPP

#include "Quaternion.hpp"

namespace Math3D {

class Frame {
private:
    // Position components
    double x, y, z;
    // Orientation quaternion
    Quaternion orientation;

public:
    // Constructors
    Frame();
    Frame(double x, double y, double z, const Quaternion& orientation);
    Frame(const Frame& other);

    // Destructor
    ~Frame();

    // Assignment operator
    Frame& operator=(const Frame& other);

    // Accessors
    double getX() const;
    double getY() const;
    double getZ() const;
    Quaternion getOrientation() const;

    // Mutators
    void setPosition(double x, double y, double z);
    void setOrientation(const Quaternion& orientation);

    // Frame operations
    void translate(double dx, double dy, double dz);
    void rotate(const Quaternion& rotation);

    // Transformation methods
    void transformPoint(double& px, double& py, double& pz) const;
    void inverseTransformPoint(double& px, double& py, double& pz) const;

    // Friend functions for stream insertion
    friend std::ostream& operator<<(std::ostream& os, const Frame& frame);
};

} // namespace Math3D

#endif // FRAME_HPP
