#ifndef FRAME_HPP
#define FRAME_HPP

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Frame {
public:
    // Constructors
    Frame();
    Frame(const glm::vec3& position, const glm::quat& orientation,
          const glm::vec3& velocity = glm::vec3(0.0f),
          const glm::vec3& angularVelocity = glm::vec3(0.0f));

    // Getters
    const glm::vec3& GetPosition() const;
    const glm::quat& GetOrientation() const;
    const glm::vec3& GetVelocity() const;
    const glm::vec3& GetAngularVelocity() const;

    // Setters
    void SetPosition(const glm::vec3& position);
    void SetOrientation(const glm::quat& orientation);
    void SetVelocity(const glm::vec3& velocity);
    void SetAngularVelocity(const glm::vec3& angularVelocity);

    // Transform a point from this frame to the world frame
    glm::vec3 TransformToWorld(const glm::vec3& localPoint) const;

    // Transform a point from the world frame to this frame
    glm::vec3 TransformToLocal(const glm::vec3& worldPoint) const;

private:
    glm::vec3 position;
    glm::quat orientation;
    glm::vec3 velocity;
    glm::vec3 angularVelocity;
};

#endif // FRAME_HPP
