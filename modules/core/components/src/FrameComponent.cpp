#include "FrameComponent.hpp"

using Frame = physics::Frame;
using Position = physics::Position;

// Constructor with owner only
FrameComponent::FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider>)
    : Frame(), Component(owner) {}

// Constructor with owner, position, and orientation
FrameComponent::FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider>, const Position& position, const math::Quaternion& orientation)
    : Frame(position, orientation), Component(owner) {}

// Constructor with owner and a Frame object
FrameComponent::FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider>, const Frame& frame)
    : Frame(frame), Component(owner) {}

// Destructor
FrameComponent::~FrameComponent() {}

// Additional functionality
void FrameComponent::translate(double dx, double dy, double dz) {
    Frame::translate(dx, dy, dz);
}

void FrameComponent::rotate(const math::Quaternion& rotation) {
    Frame::rotate(rotation);
}
