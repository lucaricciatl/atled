#ifndef FRAME_HPP
#define FRAME_HPP
#include "Position.hpp"
#include "Quaternion.hpp"
#include <ostream>
namespace physics{


class Frame {
private:
    Position position;      // Translational component
    math::Quaternion orientation; // Rotational component

public:
    // Constructors
    Frame();
    Frame(const Position& position, const math::Quaternion& orientation);
    Frame(double x, double y, double z, const math::Quaternion& orientation);
    Frame(const Frame& other);

    // Destructor
    ~Frame();

    // Assignment operator
    Frame& operator=(const Frame& other);

    // Accessors
    const Position& GetPosition() const;
    math::Quaternion GetOrientation() const;

    // Mutators
    void SetPosition(const Position& position);
    void SetOrientation(const math::Quaternion& orientation);

    // Frame operations
    void translate(double dx, double dy, double dz);
    void rotate(const math::Quaternion& rotation);

    // Transformation methods
    void transformPoint(double& px, double& py, double& pz) const;
    void inverseTransformPoint(double& px, double& py, double& pz) const;

    // Friend functions for stream insertion
    friend std::ostream& operator<<(std::ostream& os, const Frame& frame);
};

}

#endif // FRAME_HPP
