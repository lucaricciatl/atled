#include "engine.hpp"
#include "CoreEngine.hpp"
#include "InputManager.hpp"
#include "Model2DFactory.hpp"
#include "Model3DFactory.hpp"
#include <iostream>
#include "CameraFactory.hpp"
#include "CameraManager.hpp"
#include <thread>
#include <chrono>
#include <cstdlib> // For rand()
#include <mutex>
#include "Sphere.hpp"
#include <cmath> 
#include "GraphicsManager.hpp"
#include "Plane.hpp"
#include <raymath.h>

using namespace graphics;
using namespace input;

std::mutex graphicsMutex; // Mutex to protect graphicsManager access
bool running = true; // Flag to control the input thread

std::vector<std::shared_ptr<Model3D>> shapes; // To store references to the cubes and spheres
std::vector<std::shared_ptr<Line3D>> lines;  // To store references to the lines

// Camera control parameters
float cameraSpeed = 0.1f;   // Movement speed
float mouseSensitivity = 0.03f;
float zoomSpeed = 1.5f;

void Engine::OnUpdate() {
    // Handle keyboard input for camera movement
    Vector3 cameraPos = cameraManager->GetCameraPosition();
    Vector3 cameraTarget = cameraManager->GetCameraTarget();
    Vector3 forward = Vector3Normalize(Vector3Subtract(cameraTarget, cameraPos)); // Forward vector
    Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, { 0.0f, 1.0f, 0.0f })); // Right vector


    if (inputManager->IsKeyDown(KEY_W)) { // Move forward
        cameraPos = Vector3Add(cameraPos, Vector3Scale(forward, cameraSpeed));
        cameraTarget = Vector3Add(cameraTarget, Vector3Scale(forward, cameraSpeed));
    }
    if (inputManager->IsKeyDown(KEY_S)) { // Move backward
        cameraPos = Vector3Subtract(cameraPos, Vector3Scale(forward, cameraSpeed));
        cameraTarget = Vector3Subtract(cameraTarget, Vector3Scale(forward, cameraSpeed));
    }
    if (inputManager->IsKeyDown(KEY_A)) { // Move left
        cameraPos = Vector3Subtract(cameraPos, Vector3Scale(right, cameraSpeed));
        cameraTarget = Vector3Subtract(cameraTarget, Vector3Scale(right, cameraSpeed));
    }
    if (inputManager->IsKeyDown(KEY_D)) { // Move right
        cameraPos = Vector3Add(cameraPos, Vector3Scale(right, cameraSpeed));
        cameraTarget = Vector3Add(cameraTarget, Vector3Scale(right, cameraSpeed));
    }
    if (inputManager->IsKeyDown(KEY_Q)) { // Move down
        cameraPos.y -= cameraSpeed;
        cameraTarget.y -= cameraSpeed;
    }
    if (inputManager->IsKeyDown(KEY_E)) { // Move up
        cameraPos.y += cameraSpeed;
        cameraTarget.y += cameraSpeed;
    }

    if (inputManager->IsKeyDown(KEY_ESCAPE)) {
        Shutdown();
    }

    if (IsCursorOnScreen()) {
        // Handle mouse input for camera rotation
        float mouseDeltaX = inputManager->GetMouseDeltaX() * mouseSensitivity;
        float mouseDeltaY = inputManager->GetMouseDeltaY() * mouseSensitivity;
        // Reset mouse position to the center

        
        // Rotate the camera target around the position
        Matrix rotationMatrixX = MatrixRotateY(mouseDeltaX * DEG2RAD);
        Matrix rotationMatrixY = MatrixRotateX(mouseDeltaY * DEG2RAD);

        Vector3 offset = Vector3Subtract(cameraTarget, cameraPos);
        offset = Vector3Transform(offset, rotationMatrixX);
        offset = Vector3Transform(offset, rotationMatrixY);
        cameraTarget = Vector3Add(cameraPos, offset);

        // Handle mouse wheel for zooming
        float mouseWheel = inputManager->GetMouseWheelMove();
        Vector3 zoom = Vector3Scale(forward, mouseWheel * zoomSpeed);
        cameraPos = Vector3Add(cameraPos, zoom);

        // Update the camera position and target
        cameraManager->SetCameraPosition({ cameraPos.x, cameraPos.y, cameraPos.z });
        cameraManager->SetCameraTarget({ cameraTarget.x, cameraTarget.y, cameraTarget.z });
    }


}

void Engine::OnStart() {
    auto ctx = graphicsManager->GetGraphicsContext();
    ctx->SetSize(1900, 1200);
    ctx->SetTitle("3D Scene with Plane and Axes");
    auto configs = GraphicsConfig({ FLAG_FULLSCREEN_MODE, FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT });
    graphicsManager->SetConfigs(configs);
    graphicsManager->Init();

    float width = graphicsManager->GetGraphicsContext()->GetWidth();
    float height = graphicsManager->GetGraphicsContext()->GetHeight();
    float centerX = width / 2;
    float centerY = height / 2;
    inputManager->SetMouseOffset(centerX, centerY);
    inputManager->HideCursor();
    cameraManager->SetFovy(45);
    cameraManager->SetCameraProjection(CAMERA_PERSPECTIVE);
    cameraManager->SetCameraPosition({ 50.0f, 50.0f, 150.0f });
    cameraManager->SetCameraTarget({ 0.0f, 0.0f, 0.0f });

    // Create a plane
    auto plane = Model3DFactory::CreatePlane();
    plane->SetCenterPos({ 0.0f, 0.0f, 0.0f });
    plane->SetSize({ 200.0f, 200.0f });
    plane->SetColor({ 200, 200, 200, 150 }); // Light gray
    graphicsManager->AddShape(0, plane); // Add the plane to the graphics manager

    // Add axes
    Color red = { 255, 0, 0, 255 };    // X-axis color
    Color green = { 0, 255, 0, 255 };  // Y-axis color
    Color blue = { 0, 0, 255, 255 };   // Z-axis color

    // X-axis line
    auto xAxis = Model3DFactory::CreateLine3D();
    xAxis->SetStartPos({ -100.0f, 0.0f, 0.0f });
    xAxis->SetEndPos({ 100.0f, 0.0f, 0.0f });
    xAxis->SetColor(red);
    graphicsManager->AddShape(1, xAxis);

    // Y-axis line
    auto yAxis = Model3DFactory::CreateLine3D();
    yAxis->SetStartPos({ 0.0f, -100.0f, 0.0f });
    yAxis->SetEndPos({ 0.0f, 100.0f, 0.0f });
    yAxis->SetColor(green);
    graphicsManager->AddShape(1, yAxis);

    // Z-axis line
    auto zAxis = Model3DFactory::CreateLine3D();
    zAxis->SetStartPos({ 0.0f, 0.0f, -100.0f });
    zAxis->SetEndPos({ 0.0f, 0.0f, 100.0f });
    zAxis->SetColor(blue);
    graphicsManager->AddShape(1, zAxis);
}


void Engine::OnRender() {
    std::lock_guard<std::mutex> lock(graphicsMutex);

    graphicsManager->Render();
    graphicsManager->Clear(BLACK);

}

void Engine::OnShutdown() {
    std::cout << "Performing engine shutdown tasks..." << std::endl;
}
