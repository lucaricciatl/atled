#include "FreeCameraComponent.hpp"

#include <cmath>

#include "Vector3.hpp"

void FreeCameraComponent::Update(double deltaTime) {
    float cameraSpeed = 0.1f;  // Movement speed
    float mouseSensitivity = 0.1f;
    float zoomSpeed = 1.5f;

    math::Vector3 cameraPos = mCameraManager->GetCameraPosition();
    math::Vector3 cameraTarget = mCameraManager->GetCameraTarget();

    // Forward vector: normalized direction from position to target
    math::Vector3 forward = (cameraTarget - cameraPos).normalized();

    // Right vector: perpendicular to forward and up vectors
    math::Vector3 right = forward.cross(math::Vector3(0.0f, 1.0f, 0.0f)).normalized();

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
        cameraPos.setY(cameraPos.getY() - cameraSpeed);        // Using getter and setter
        cameraTarget.setY(cameraTarget.getY() - cameraSpeed);  // Ensure consistency
    }

    if (mInputManager->IsKeyDown(raylib::KEY_E)) {             // Move up
        cameraPos.setY(cameraPos.getY() + cameraSpeed);        // Using getter and setter
        cameraTarget.setY(cameraTarget.getY() + cameraSpeed);  // Ensure consistency
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
        auto roffset = raylib::Vector3Transform({offset.getX(), offset.getY(), offset.getZ()}, rotationMatrixX);
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