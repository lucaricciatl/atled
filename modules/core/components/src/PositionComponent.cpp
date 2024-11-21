#include "PositionComponent.hpp"


using Position = physics::Position;

// Constructor with owner only
PositionComponent::PositionComponent(Entity* owner) 
    : Position(), Component(owner) {}

// Constructor with owner and x, y, z values
PositionComponent::PositionComponent(Entity* owner, double x, double y, double z) 
    : Position(x, y, z), Component(owner) {}

// Constructor with owner and a Position object
PositionComponent::PositionComponent(Entity* owner, const Position& position) 
    : Position(position), Component(owner) {}

// Destructor
PositionComponent::~PositionComponent() {}

// Additional functionality
void PositionComponent::translate(double dx, double dy, double dz) {
    Position::translate(dx, dy, dz);
}
    