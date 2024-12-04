#ifndef CONTROLLERCOMPONENT_HPP
#define CONTROLLERCOMPONENT_HPP

#include "Component.hpp"
#include <Action.hpp>
#include "ServiceProvider.hpp"
#include <InputManager.hpp>
#include "../../../external/raylib/src/raymath.h"



class FreeCameraComponent : public Component {
public:
    FreeCameraComponent(Entity* owner, std::shared_ptr<ServiceProvider> aServiceProvider) : Component(owner){
        mCameraManager = aServiceProvider->GetCameraManager();
        mInputManager = aServiceProvider->GetInputManager();
    };


    void Update(double deltaTime) override;

private:
    std::shared_ptr<input::InputManager> mInputManager;
    std::shared_ptr<graphics::CameraManager> mCameraManager;

};

#endif // PLAYERCONTROLLER_HPP