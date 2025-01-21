#ifndef FRAME_COMPONENT_HPP
#define FRAME_COMPONENT_HPP

#include "Component.hpp"
#include "Frame.hpp"

using Frame = physics::Frame;
using Position = physics::Position;

class FrameComponent : public Component {
   public:
    // Constructors
    FrameComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> aServiceProvider);
    FrameComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> aServiceProvider, const Position& aPosition,
                   const math::Quaternion& aOrientation);
    FrameComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> aServiceProvider, std::shared_ptr<Frame> aFrame);
    // Getters
    std::shared_ptr<Frame> GetFrame() const { return mFrame; };
    std::shared_ptr<Position> GetPosition() const;
    math::Quaternion GetOrientation() const;

    // Setters
    void SetPosition(float x, float y, float z);
    void SetOrientation(const math::Quaternion& aOrientation);
    void SetFrame(std::shared_ptr<Frame> aFrame);
    void SetPosition(const math::Vector3& position);
    // Destructor
    ~FrameComponent() override;

   private:
    std::shared_ptr<Frame> mFrame;
};

#endif  // FRAME_COMPONENT_HPP
