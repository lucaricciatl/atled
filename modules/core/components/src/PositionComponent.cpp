#include "PositionComponent.hpp"

using Position = physics::Position;

// Constructor with owner only
PositionComponent::PositionComponent(Entity* aOwner, std::shared_ptr<ServiceProvider>)
    : Position(), Component(aOwner) {}

// Constructor with owner and x, y, z values
PositionComponent::PositionComponent(Entity* aOwner, std::shared_ptr<ServiceProvider>, double aX, double aY, double aZ)
    : Position(aX, aY, aZ), Component(aOwner) {}

// Constructor with owner and a Position object
PositionComponent::PositionComponent(Entity* aOwner, std::shared_ptr<ServiceProvider>, const Position& position)
    : Position(position), Component(aOwner) {}

// Destructor
PositionComponent::~PositionComponent() {}

// Additional functionality
void PositionComponent::translate(double aDx, double aDy, double aDz) { Position::Translate(aDx, aDy, aDz); }
