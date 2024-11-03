#include "Frame.hpp"

// Default constructor
Frame::Frame()
    : position(0.0f), orientation(glm::quat_identity<float, glm::defaultp>()),
      velocity(0.0f), angularVelocity(0.0f) {}

// Parameterized constructor
Frame::Frame(const glm::vec3& position, const glm::quat& orientation,
             const glm::vec3& velocity, const glm::vec3& angularVelocity)
    : position(position), orientation(orientation),
      velocity(velocity), angularVelocity(angularVelocity) {}

// Getters
const glm::vec3& Frame::GetPosition() const {
    return position;
}

const glm::quat& Frame::GetOrientation() const {
    return orientation;
}

const glm::vec3& Frame::GetVelocity() const {
    return velocity;
}

const glm::vec3& Frame::GetAngularVelocity() const {
    return angularVelocity;
}

// Setters
void Frame::SetPosition(const glm::vec3& position) {
    this->position = position;
}

void Frame::SetOrientation(const glm::quat& orientation) {
    this->orientation = orientation;
}

void Frame::SetVelocity(const glm::vec3& velocity) {
    this->velocity = velocity;
}

void Frame::SetAngularVelocity(const glm::vec3& angularVelocity) {
    this->angularVelocity = angularVelocity;
}

// Transform a point from this frame to the world frame
glm::vec3 Frame::TransformToWorld(const glm::vec3& localPoint) const {
    return position + orientation * localPoint;
}

// Transform a point from the world frame to this frame
glm::vec3 Frame::TransformToLocal(const glm::vec3& worldPoint) const {
    return glm::inverse(orientation) * (worldPoint - position);
}
