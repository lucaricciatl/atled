#include "FrameComponent.hpp"

using Frame = physics::Frame;
using Position = physics::Position;

// Constructor with owner only
FrameComponent::FrameComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
    : Component(aOwner), mFrame(std::make_shared<Frame>()) {}

// Constructor with owner, position, and orientation
FrameComponent::FrameComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider,
                               const Position& position, const math::Quaternion& orientation)
    : Component(aOwner), mFrame(std::make_shared<Frame>()) {}

// Constructor with owner and a Frame object
FrameComponent::FrameComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider,
                               std::shared_ptr<Frame> aframe)
    : Component(aOwner), mFrame(aframe) {}

// Destructor
FrameComponent::~FrameComponent() {}

// Set position
void FrameComponent::SetPosition(float x, float y, float z) {
    if (mFrame) {
        mFrame->SetPosition(x, y, z);
    }
}

void FrameComponent::SetPosition(const math::Vector3& position) {
    if (mFrame) {
        mFrame->SetPosition(position.GetX(), position.GetY(), position.GetZ());
    }
    }
// Set orientation
void FrameComponent::SetOrientation(const math::Quaternion& orientation) {
    if (mFrame) {
        mFrame->SetOrientation(orientation);
    }
}

// Set entire frame
void FrameComponent::SetFrame(std::shared_ptr<Frame> aframe) {
    if (mFrame) {
        mFrame = aframe;
    }
}

std::shared_ptr<Position> FrameComponent::GetPosition() const {
    if (mFrame) {
        return mFrame->GetPosition();
    }
    return std::make_shared<Position>(0.0f, 0.0f, 0.0f);  // Default position if frame is null
}

// Get the orientation of the frame
math::Quaternion FrameComponent::GetOrientation() const {
    if (mFrame) {
        return mFrame->GetOrientation();
    }
    return math::Quaternion(0.0f, 0.0f, 0.0f, 1.0f);  // Default orientation (identity quaternion) if frame is null
}
