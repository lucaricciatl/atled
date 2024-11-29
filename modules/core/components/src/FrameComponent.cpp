#include "FrameComponent.hpp"

using Frame = physics::Frame;
using Position = physics::Position;

// Constructor with owner only
FrameComponent::FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider)
    : Component(owner), frame(std::make_shared<Frame>()) {}

// Constructor with owner, position, and orientation
FrameComponent::FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider , const Position& position, const math::Quaternion& orientation)
    : Component(owner), frame(std::make_shared<Frame>()) {}

// Constructor with owner and a Frame object
FrameComponent::FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider, const Frame& frame)
    : Component(owner),  frame(std::make_shared<Frame>()) {}

// Destructor
FrameComponent::~FrameComponent() {}

#include "FrameComponent.hpp"

// Set position
void FrameComponent::SetPosition(float x, float y, float z) {
    if (frame) {
        frame->SetPosition(x, y, z);
    }
}

// Set orientation
void FrameComponent::SetOrientation(const math::Quaternion& orientation) {
    if (frame) {
        frame->SetOrientation(orientation);
    }
}

// Set entire frame
void FrameComponent::SetFrame(const Frame& newFrame) {
    if (frame) {
        *frame = newFrame;
    }
}

std::shared_ptr<Position> FrameComponent::GetPosition() const {
    if (frame) {
        return frame->GetPosition();
    }
    return std::make_shared<Position>(0.0f, 0.0f, 0.0f); // Default position if frame is null
}


// Get the orientation of the frame
math::Quaternion FrameComponent::GetOrientation() const {
    if (frame) {
        return frame->GetOrientation();
    }
    return math::Quaternion(0.0f, 0.0f, 0.0f, 1.0f); // Default orientation (identity quaternion) if frame is null
}
