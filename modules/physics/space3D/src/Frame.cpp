#include "Frame.hpp"
#include "Position.hpp"
#include "Quaternion.hpp"
#include "Vector3.hpp"

namespace physics {

    // Constructors
    Frame::Frame() : position(std::make_shared<Position>()), orientation(1.0, 0.0, 0.0, 0.0) {}

    Frame::Frame(const std::shared_ptr<Position>& position, const math::Quaternion& orientation)
        : position(position), orientation(orientation.Normalized()) {}

    Frame::Frame(double x, double y, double z, const math::Quaternion& orientation)
        : position(std::make_shared<Position>(x, y, z)), orientation(orientation.Normalized()) {}

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

    math::Vector3 Frame::GetVectorPosition() const {
        return math::Vector3(position->GetX(), position->GetY(), position->GetZ());
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
            position->SetX(x);
            position->SetY(y);
            position->SetZ(z);
        }
    }

    void Frame::SetOrientation(const math::Quaternion& orientation) { this->orientation = orientation.Normalized(); }

    // Frame operations
    void Frame::translate(double dx, double dy, double dz) {
        if (!position) {
            position = std::make_shared<Position>(dx, dy, dz);
        }
        else {
            position->Translate(dx, dy, dz);
        }
    }

    void Frame::rotate(const math::Quaternion& rotation) { orientation = (rotation * orientation).Normalized(); }

    math::Vector3 Frame::transformPointToWorld(const math::Vector3& localPoint) const {
        // Step 1: Rotate the point using the frame's orientation
        math::Vector3 rotatedPoint = orientation.RotateVector(localPoint);

        // Step 2: Translate the rotated point using the frame's position
        math::Vector3 worldPosition = GetVectorPosition();
        return rotatedPoint + worldPosition;
    }

    // Transformation methods
    void Frame::transformPoint(double& px, double& py, double& pz) const {
        // Apply rotation using the orientation quaternion
        math::Quaternion point(0, px, py, pz);
        math::Quaternion rotatedPoint = orientation * point * orientation.Conjugate();

        // Apply translation
        if (position) {
            px = rotatedPoint.GetX() + position->GetX();
            py = rotatedPoint.GetY() + position->GetY();
            pz = rotatedPoint.GetZ() + position->GetZ();
        }
        else {
            px = rotatedPoint.GetX();
            py = rotatedPoint.GetY();
            pz = rotatedPoint.GetZ();
        }
    }

    void Frame::inverseTransformPoint(double& px, double& py, double& pz) const {
        // Reverse translation
        if (position) {
            px -= position->GetX();
            py -= position->GetY();
            pz -= position->GetZ();
        }

        // Reverse rotation using the conjugate of the orientation quaternion
        math::Quaternion point(0, px, py, pz);
        math::Quaternion rotatedPoint = orientation.Conjugate() * point * orientation;

        px = rotatedPoint.GetX();
        py = rotatedPoint.GetY();
        pz = rotatedPoint.GetZ();
    }

    // Friend function for stream insertion
    std::ostream& operator<<(std::ostream& os, const Frame& frame) {
        if (frame.position) {
            os << "Frame(Position: [" << frame.position->GetX() << ", " << frame.position->GetY() << ", "
               << frame.position->GetZ() << "], Orientation: " << frame.orientation << ")";
        }
        else {
            os << "Frame(Position: [null], Orientation: " << frame.orientation << ")";
        }
        return os;
    }

} // namespace physics
