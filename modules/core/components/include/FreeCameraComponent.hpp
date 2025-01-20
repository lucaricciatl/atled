#ifndef CONTROLLERCOMPONENT_HPP
#define CONTROLLERCOMPONENT_HPP

#include <Action.hpp>
#include <InputManager.hpp>

#include "../../../external/raylib/src/raymath.h"
#include "Component.hpp"
#include "ServiceProvider.hpp"

class FreeCameraComponent : public Component {
   public:
    FreeCameraComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> aServiceProvider) : Component(aOwner) {
        mCameraManager = aServiceProvider->GetCameraManager();
        mInputManager = aServiceProvider->GetInputManager();
    };

    void Update(double deltaTime) override;

   private:
    std::shared_ptr<input::InputManager> mInputManager;
    std::shared_ptr<graphics::CameraManager> mCameraManager;
};

#endif  // PLAYERCONTROLLER_HPP