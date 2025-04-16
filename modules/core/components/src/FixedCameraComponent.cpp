#include "FixedCameraComponent.hpp"

#include <cmath>

#include "Vector3.hpp"
void FixedCameraComponent::Update(double aDt) {


    math::Vector3 cameraPos = mCameraManager->GetCameraPosition();
    math::Vector3 cameraTarget = mCameraManager->GetCameraTarget();

    // Update the camera position and target
    mCameraManager->SetCameraPosition(cameraPos);
    mCameraManager->SetCameraTarget(cameraTarget);
};