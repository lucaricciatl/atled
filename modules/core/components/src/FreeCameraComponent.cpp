#include "FreeCameraComponent.hpp"

#include <cmath>

#include "Vector3.hpp"

void FreeCameraComponent::Update(double aDt) {
    float cameraSpeed = 0.1f;  // Movement speed
    float mouseSensitivity = 0.1f;
    float zoomSpeed = 1.5f;

    math::Vector3 cameraPos = mCameraManager->GetCameraPosition();
    math::Vector3 cameraTarget = mCameraManager->GetCameraTarget();

    // Forward vector: normalized direction from position to target
    math::Vector3 forward = (cameraTarget - cameraPos).Normalized();

    // Right vector: perpendicular to forward and up vectors
    math::Vector3 right = forward.Cross(math::Vector3(0.0f, 1.0f, 0.0f)).Normalized();

    // Handle input for movement
    if (mInputManager->IsKeyDown(raylib::KEY_W)) {  // Move forward
        cameraPos = cameraPos + forward * cameraSpeed;
        cameraTarget = cameraTarget + forward * cameraSpeed;
    }
    if (mInputManager->IsKeyDown(raylib::KEY_S)) {  // Move backward
        cameraPos = cameraPos - forward * cameraSpeed;
        cameraTarget = cameraTarget - forward * cameraSpeed;
    }
    if (mInputManager->IsKeyDown(raylib::KEY_A)) {  // Move left
        cameraPos = cameraPos - right * cameraSpeed;
        cameraTarget = cameraTarget - right * cameraSpeed;
    }
    if (mInputManager->IsKeyDown(raylib::KEY_D)) {  // Move right
        cameraPos = cameraPos + right * cameraSpeed;
        cameraTarget = cameraTarget + right * cameraSpeed;
    }
    if (mInputManager->IsKeyDown(raylib::KEY_Q)) {             // Move down
        cameraPos.SetY(cameraPos.GetY() - cameraSpeed);        // Using getter and setter
        cameraTarget.SetY(cameraTarget.GetY() - cameraSpeed);  // Ensure consistency
    }

    if (mInputManager->IsKeyDown(raylib::KEY_E)) {             // Move up
        cameraPos.SetY(cameraPos.GetY() + cameraSpeed);        // Using getter and setter
        cameraTarget.SetY(cameraTarget.GetY() + cameraSpeed);  // Ensure consistency
    }

    // Update the camera manager with the new position and target
    mCameraManager->SetCameraPosition(cameraPos);
    mCameraManager->SetCameraTarget(cameraTarget);

    if (raylib::IsCursorOnScreen() && raylib::IsMouseButtonDown(1)) {
        // Handle mouse input for camera rotation
        float mouseDeltaX = -mInputManager->GetMouseDeltaX() * mouseSensitivity;
        float mouseDeltaY = -mInputManager->GetMouseDeltaY() * mouseSensitivity;

        // Rotate the camera target around the position
        raylib::Matrix rotationMatrixX = raylib::MatrixRotateY(mouseDeltaX * DEG2RAD);
        raylib::Matrix rotationMatrixY = raylib::MatrixRotateX(mouseDeltaY * DEG2RAD);
        math::Vector3 offset = cameraTarget - cameraPos;
        auto roffset = raylib::Vector3Transform({offset.GetX(), offset.GetY(), offset.GetZ()}, rotationMatrixX);
        auto soffset = raylib::Vector3Transform({roffset.x, roffset.y, roffset.z}, rotationMatrixY);
        cameraTarget = cameraPos + math::Vector3(soffset.x, soffset.y, soffset.z);

        // Handle mouse wheel for zooming
        float mouseWheel = mInputManager->GetMouseWheelMove();
        math::Vector3 zoom = forward * mouseWheel * zoomSpeed;
        cameraPos = cameraPos + zoom;
    }
    // Update the camera position and target
    mCameraManager->SetCameraPosition(cameraPos);
    mCameraManager->SetCameraTarget(cameraTarget);
};