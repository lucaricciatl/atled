#include "FreeCameraComponent.hpp"


void FreeCameraComponent::Update(double deltaTime) {
    float cameraSpeed = 0.1f;   // Movement speed
    float mouseSensitivity = 0.1f;
    float zoomSpeed = 1.5f;

    raylib::Vector3 cameraPos = mCameraManager->GetCameraPosition();
    raylib::Vector3 cameraTarget = mCameraManager->GetCameraTarget();
    raylib::Vector3 forward = Vector3Normalize(Vector3Subtract(cameraTarget, cameraPos)); // Forward vector
    raylib::Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, { 0.0f, 1.0f, 0.0f })); // Right vector


    if (mInputManager->IsKeyDown(raylib::KEY_W)) { // Move forward
        cameraPos = raylib::Vector3Add(cameraPos, raylib::Vector3Scale(forward, cameraSpeed));
        cameraTarget = raylib::Vector3Add(cameraTarget, Vector3Scale(forward, cameraSpeed));
    }
    if (mInputManager->IsKeyDown(raylib::KEY_S)) { // Move backward
        cameraPos = raylib::Vector3Subtract(cameraPos, raylib::Vector3Scale(forward, cameraSpeed));
        cameraTarget = raylib::Vector3Subtract(cameraTarget, Vector3Scale(forward, cameraSpeed));
    }
    if (mInputManager->IsKeyDown(raylib::KEY_A)) { // Move left
        cameraPos = raylib::Vector3Subtract(cameraPos, raylib::Vector3Scale(right, cameraSpeed));
        cameraTarget = raylib::Vector3Subtract(cameraTarget, raylib::Vector3Scale(right, cameraSpeed));
    }
    if (mInputManager->IsKeyDown(raylib::KEY_D)) { // Move right
        cameraPos = raylib::Vector3Add(cameraPos, raylib::Vector3Scale(right, cameraSpeed));
        cameraTarget = raylib::Vector3Add(cameraTarget, raylib::Vector3Scale(right, cameraSpeed));
    }
    if (mInputManager->IsKeyDown(raylib::KEY_Q)) { // Move down
        cameraPos.y -= cameraSpeed;
        cameraTarget.y -= cameraSpeed;
    }
    if (mInputManager->IsKeyDown(raylib::KEY_E)) { // Move up
        cameraPos.y += cameraSpeed;
        cameraTarget.y += cameraSpeed;
    }

    if (raylib::IsCursorOnScreen() && raylib::IsMouseButtonDown(1)) {
        // Handle mouse input for camera rotation
        float mouseDeltaX = -mInputManager->GetMouseDeltaX() * mouseSensitivity;
        float mouseDeltaY = -mInputManager->GetMouseDeltaY() * mouseSensitivity;

        // Rotate the camera target around the position
        raylib::Matrix rotationMatrixX = raylib::MatrixRotateY(mouseDeltaX * DEG2RAD);
        raylib::Matrix rotationMatrixY = raylib::MatrixRotateX(mouseDeltaY * DEG2RAD);
        raylib::Vector3 offset = raylib::Vector3Subtract(cameraTarget, cameraPos);
        offset = Vector3Transform(offset, rotationMatrixX);
        offset = Vector3Transform(offset, rotationMatrixY);
        cameraTarget = Vector3Add(cameraPos, offset);

        // Handle mouse wheel for zooming
        float mouseWheel = mInputManager->GetMouseWheelMove();
        raylib::Vector3 zoom = raylib::Vector3Scale(forward, mouseWheel * zoomSpeed);
        cameraPos = raylib::Vector3Add(cameraPos, zoom);

    }
    // Update the camera position and target
    mCameraManager->SetCameraPosition({ cameraPos.x, cameraPos.y, cameraPos.z });
    mCameraManager->SetCameraTarget({ cameraTarget.x, cameraTarget.y, cameraTarget.z });
};