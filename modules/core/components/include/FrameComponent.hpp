#ifndef FRAME_COMPONENT_HPP
#define FRAME_COMPONENT_HPP

#include "Component.hpp"
#include "Frame.hpp"

using Frame = physics::Frame;
using Position = physics::Position;


class FrameComponent : public Component {
public:
    // Constructors
    FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider>);
    FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider>, const Position& position, const math::Quaternion& orientation);
    FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider>, const Frame& frame);
    std::shared_ptr<Frame> GetFrame(){return frame;};
    // Destructor
    ~FrameComponent() override;



    std::shared_ptr<Frame> frame;
};

#endif // FRAME_COMPONENT_HPP
