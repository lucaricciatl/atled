#include "FreeCameraComponent.hpp"


void FreeCameraComponent::Update(double deltaTime) {
    float cameraSpeed = 0.1f;   // Movement speed
    float mouseSensitivity = 0.1f;
    float zoomSpeed = 1.5f;

    Vector3 cameraPos = mCameraManager->GetCameraPosition();
    Vector3 cameraTarget = mCameraManager->GetCameraTarget();
    Vector3 forward = Vector3Normalize(Vector3Subtract(cameraTarget, cameraPos)); // Forward vector
    Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, { 0.0f, 1.0f, 0.0f })); // Right vector


    if (mInputManager->IsKeyDown(KEY_W)) { // Move forward
        cameraPos = Vector3Add(cameraPos, Vector3Scale(forward, cameraSpeed));
        cameraTarget = Vector3Add(cameraTarget, Vector3Scale(forward, cameraSpeed));
    }
    if (mInputManager->IsKeyDown(KEY_S)) { // Move backward
        cameraPos = Vector3Subtract(cameraPos, Vector3Scale(forward, cameraSpeed));
        cameraTarget = Vector3Subtract(cameraTarget, Vector3Scale(forward, cameraSpeed));
    }
    if (mInputManager->IsKeyDown(KEY_A)) { // Move left
        cameraPos = Vector3Subtract(cameraPos, Vector3Scale(right, cameraSpeed));
        cameraTarget = Vector3Subtract(cameraTarget, Vector3Scale(right, cameraSpeed));
    }
    if (mInputManager->IsKeyDown(KEY_D)) { // Move right
        cameraPos = Vector3Add(cameraPos, Vector3Scale(right, cameraSpeed));
        cameraTarget = Vector3Add(cameraTarget, Vector3Scale(right, cameraSpeed));
    }
    if (mInputManager->IsKeyDown(KEY_Q)) { // Move down
        cameraPos.y -= cameraSpeed;
        cameraTarget.y -= cameraSpeed;
    }
    if (mInputManager->IsKeyDown(KEY_E)) { // Move up
        cameraPos.y += cameraSpeed;
        cameraTarget.y += cameraSpeed;
    }

    if (raylib::IsCursorOnScreen() && IsMouseButtonDown(1)) {
        // Handle mouse input for camera rotation
        float mouseDeltaX = -mInputManager->GetMouseDeltaX() * mouseSensitivity;
        float mouseDeltaY = -mInputManager->GetMouseDeltaY() * mouseSensitivity;

        // Rotate the camera target around the position
        Matrix rotationMatrixX = MatrixRotateY(mouseDeltaX * DEG2RAD);
        Matrix rotationMatrixY = MatrixRotateX(mouseDeltaY * DEG2RAD);
        Vector3 offset = Vector3Subtract(cameraTarget, cameraPos);
        offset = Vector3Transform(offset, rotationMatrixX);
        offset = Vector3Transform(offset, rotationMatrixY);
        cameraTarget = Vector3Add(cameraPos, offset);

        // Handle mouse wheel for zooming
        float mouseWheel = mInputManager->GetMouseWheelMove();
        Vector3 zoom = Vector3Scale(forward, mouseWheel * zoomSpeed);
        cameraPos = Vector3Add(cameraPos, zoom);

    }
    // Update the camera position and target
    mCameraManager->SetCameraPosition({ cameraPos.x, cameraPos.y, cameraPos.z });
    mCameraManager->SetCameraTarget({ cameraTarget.x, cameraTarget.y, cameraTarget.z });
};