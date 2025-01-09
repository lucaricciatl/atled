#ifndef FRAME_COMPONENT_HPP
#define FRAME_COMPONENT_HPP

#include "Component.hpp"
#include "Frame.hpp"

using Frame = physics::Frame;
using Position = physics::Position;

class FrameComponent : public Component {
   public:
    // Constructors
    FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider);
    FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider, const Position& position,
                   const math::Quaternion& orientation);
    FrameComponent(Entity* owner, std::shared_ptr<ServiceProvider> serviceProvider, std::shared_ptr<Frame> aframe);
    // Getters
    std::shared_ptr<Frame> GetFrame() const { return frame; };
    std::shared_ptr<Position> GetPosition() const;
    math::Quaternion GetOrientation() const;

    // Setters
    void SetPosition(float x, float y, float z);
    void SetOrientation(const math::Quaternion& orientation);
    void SetFrame(std::shared_ptr<Frame> aframe);

    // Destructor
    ~FrameComponent() override;

   private:
    std::shared_ptr<Frame> frame;
};

#endif  // FRAME_COMPONENT_HPP
