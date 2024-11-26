#include "FrameComponent.hpp"

using Frame = physics::Frame;
using Position = physics::Position;

// Constructor with owner only
FrameComponent::FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider)
    : Component(owner) {}

// Constructor with owner, position, and orientation
FrameComponent::FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider , const Position& position, const math::Quaternion& orientation)
    : Component(owner) {}

// Constructor with owner and a Frame object
FrameComponent::FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider, const Frame& frame)
    : Component(owner) {}

// Destructor
FrameComponent::~FrameComponent() {}

