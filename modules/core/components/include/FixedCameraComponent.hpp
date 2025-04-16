#ifndef FIXEDCAMERACOMPONENT_HPP
#define FIXEDCAMERACOMPONENT_HPP


#include <Action.hpp>
#include <InputManager.hpp>

#include "../../../external/raylib/src/raymath.h"
#include "Component.hpp"
#include "ServiceProvider.hpp"

class FixedCameraComponent : public Component {
   public:
   FixedCameraComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> aServiceProvider) : Component(aOwner) {
        mCameraManager = aServiceProvider->GetCameraManager();
        mInputManager = aServiceProvider->GetInputManager();
    };

    void Update(double deltaTime) override;

    void SetPosition(const math::Vector3& aPosition) {
        mCameraManager->SetCameraPosition(aPosition);
    }
    void SetTarget(const math::Vector3& aTarget) {
        mCameraManager->SetCameraTarget(aTarget);
    };
    math::Vector3 GetPosition() const { return mCameraManager->GetCameraPosition(); }
    math::Vector3 GetTarget() const { return mCameraManager->GetCameraTarget(); };

   private:
    std::shared_ptr<input::InputManager> mInputManager;
    std::shared_ptr<graphics::CameraManager> mCameraManager;
};

#endif  // PLAYERCONTROLLER_HPP