#include "PositionComponent.hpp"

using Position = physics::Position;

// Constructor with owner only
PositionComponent::PositionComponent(Entity* owner, std::shared_ptr<ServiceProvider>) : Position(), Component(owner) {}

// Constructor with owner and x, y, z values
PositionComponent::PositionComponent(Entity* owner, std::shared_ptr<ServiceProvider>, double x, double y, double z)
    : Position(x, y, z), Component(owner) {}

// Constructor with owner and a Position object
PositionComponent::PositionComponent(Entity* owner, std::shared_ptr<ServiceProvider>, const Position& position)
    : Position(position), Component(owner) {}

// Destructor
PositionComponent::~PositionComponent() {}

// Additional functionality
void PositionComponent::translate(double dx, double dy, double dz) { Position::Translate(dx, dy, dz); }
