#ifndef POSITION_COMPONENT_HPP
#define POSITION_COMPONENT_HPP

#include "Component.hpp"
#include "Position.hpp"

using Position = physics::Position;

class PositionComponent : public Position, public Component {
public:
    // Constructors
    PositionComponent(Entity* owner, std::shared_ptr<ServiceProvider>);
    PositionComponent(Entity* owner, std::shared_ptr<ServiceProvider> ,double x, double y, double z);
    PositionComponent(Entity* owner, std::shared_ptr<ServiceProvider> ,const Position& position);

    // Destructor
    ~PositionComponent() override;

    // Additional functionality
    void translate(double dx, double dy, double dz);
};

#endif // POSITION_COMPONENT_HPP
