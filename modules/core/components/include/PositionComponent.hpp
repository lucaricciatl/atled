#ifndef POSITION_COMPONENT_HPP
#define POSITION_COMPONENT_HPP

#include "Component.hpp"
#include "Position.hpp"

using Position = physics::Position;

class PositionComponent : public Position, public Component {
   public:
    // Constructors
    PositionComponent(Entity* aOwner, std::shared_ptr<ServiceProvider>);
    PositionComponent(Entity* aOwner, std::shared_ptr<ServiceProvider>, double aX, double aY, double aZ);
    PositionComponent(Entity* aOwner, std::shared_ptr<ServiceProvider>, const Position& aPosition);

    // Destructor
    ~PositionComponent() override;

    // Additional functionality
    void translate(double aDx, double aDy, double aDz);
};

#endif  // POSITION_COMPONENT_HPP
