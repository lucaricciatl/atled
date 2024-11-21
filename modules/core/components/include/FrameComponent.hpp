#ifndef FRAME_COMPONENT_HPP
#define FRAME_COMPONENT_HPP

#include "Component.hpp"
#include "Frame.hpp"

using Frame = physics::Frame;
using Position = physics::Position;


class FrameComponent : public Frame, public Component {
public:
    // Constructors
    FrameComponent(Entity* owner);
    FrameComponent(Entity* owner, const Position& position, const math::Quaternion& orientation);
    FrameComponent(Entity* owner, const Frame& frame);

    // Destructor
    ~FrameComponent() override;

    // Additional functionality
    void translate(double dx, double dy, double dz);
    void rotate(const math::Quaternion& rotation);
};

#endif // FRAME_COMPONENT_HPP
