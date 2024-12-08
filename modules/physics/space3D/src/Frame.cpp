#include "Frame.hpp"
#include "Position.hpp"
#include "Quaternion.hpp"

namespace physics {

    // Constructors
    Frame::Frame() : position(std::make_shared<Position>()), orientation(1.0, 0.0, 0.0, 0.0) {}

    Frame::Frame(const std::shared_ptr<Position>& position, const math::Quaternion& orientation)
        : position(position), orientation(orientation.normalized()) {}

    Frame::Frame(double x, double y, double z, const math::Quaternion& orientation)
        : position(std::make_shared<Position>(x, y, z)), orientation(orientation.normalized()) {}

    Frame::Frame(const Frame& other)
        : position(other.position), orientation(other.orientation) {}

    Frame::~Frame() {}

    Frame& Frame::operator=(const Frame& other) {
        if (this != &other) {
            position = other.position;
            orientation = other.orientation;
        }
        return *this;
    }

    // Accessors
    std::shared_ptr<Position> Frame::GetPosition() const {
        return position;
    }

    math::Quaternion Frame::GetOrientation() const {
        return orientation;
    }

    // Mutators
    void Frame::SetPosition(std::shared_ptr<Position>& position) {
        this->position = position;
    }

    void Frame::SetPosition(double x, double y, double z) {
        if (!position) {
            position = std::make_shared<Position>(x, y, z);
        }
        else {
            position->setX(x);
            position->setY(y);
            position->setZ(z);
        }
    }

    void Frame::SetOrientation(const math::Quaternion& orientation) {
        this->orientation = orientation.normalized();
    }

    // Frame operations
    void Frame::translate(double dx, double dy, double dz) {
        if (!position) {
            position = std::make_shared<Position>(dx, dy, dz);
        }
        else {
            position->translate(dx, dy, dz);
        }
    }

    void Frame::rotate(const math::Quaternion& rotation) {
        orientation = (rotation * orientation).normalized();
    }

    // Transformation methods
    void Frame::transformPoint(double& px, double& py, double& pz) const {
        // Apply rotation using the orientation quaternion
        math::Quaternion point(0, px, py, pz);
        math::Quaternion rotatedPoint = orientation * point * orientation.conjugate();

        // Apply translation
        if (position) {
            px = rotatedPoint.getX() + position->getX();
            py = rotatedPoint.getY() + position->getY();
            pz = rotatedPoint.getZ() + position->getZ();
        }
        else {
            px = rotatedPoint.getX();
            py = rotatedPoint.getY();
            pz = rotatedPoint.getZ();
        }
    }

    void Frame::inverseTransformPoint(double& px, double& py, double& pz) const {
        // Reverse translation
        if (position) {
            px -= position->getX();
            py -= position->getY();
            pz -= position->getZ();
        }

        // Reverse rotation using the conjugate of the orientation quaternion
        math::Quaternion point(0, px, py, pz);
        math::Quaternion rotatedPoint = orientation.conjugate() * point * orientation;

        px = rotatedPoint.getX();
        py = rotatedPoint.getY();
        pz = rotatedPoint.getZ();
    }

    // Friend function for stream insertion
    std::ostream& operator<<(std::ostream& os, const Frame& frame) {
        if (frame.position) {
            os << "Frame(Position: [" << frame.position->getX() << ", " << frame.position->getY() << ", "
                << frame.position->getZ() << "], Orientation: " << frame.orientation << ")";
        }
        else {
            os << "Frame(Position: [null], Orientation: " << frame.orientation << ")";
        }
        return os;
    }

} // namespace physics
