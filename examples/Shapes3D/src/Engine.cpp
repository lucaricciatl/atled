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

using namespace graphics;
using namespace input;

std::mutex graphicsMutex; // Mutex to protect graphicsManager access
bool running = true; // Flag to control the input thread

std::vector<std::shared_ptr<Cube>> cubes; // To store references to the cubes
std::vector<std::shared_ptr<Line3D>> lines;  // To store references to the lines

void Engine::OnUpdate() {
    static float angle = 0.0f;           // Angle of rotation in radians for camera
    static float colorShift = 10.0f;     // For smooth color cycling
    const float radius = 120.0f;         // Distance from the object
    const float rotationSpeed = 0.005f;  // Speed of rotation for camera
    const float colorSpeed = 0.1f;       // Speed of color change

    // Update the angle for camera rotation
    angle += rotationSpeed;

    // Update the color shift
    colorShift += colorSpeed;

    // Calculate the new camera position
    float x = radius * cos(angle);
    float y = radius * sin(angle);

    // Set the new camera position and target
    cameraManager->SetCameraPosition({ x, y, 120 }); // Camera rotates around
    cameraManager->SetCameraTarget({ 25, 25, 25 });    // Keep the target fixed on the object

    // Rotate cubes and change their colors smoothly
    float phaseOffset = 0.1f; // Offset for different color phases per cube
    int index = 0;            // Cube index for unique phase

    for (auto& cube : cubes) {
        if (cube) {
            // Calculate unique phase for each cube
            float phase = colorShift + index * phaseOffset;

            // Smooth color components using sine wave
            int red = static_cast<int>((sin(phase) + 1) * 127.5);   // Range: 0-255
            int green = static_cast<int>((sin(phase + 2.0f) + 1) * 127.5); // Offset for green
            int blue = static_cast<int>((sin(phase + 4.0f) + 1) * 127.5);  // Offset for blue

            // Set the cube color
            cube->SetColor(Color(red, green, blue, 120));

            ++index; // Increment index for unique phase per cube
        }
    }
}

void Engine::OnStart() {
    auto ctx = graphicsManager->GetGraphicsContext();
    ctx->SetSize(900, 900);
    ctx->SetTitle("Window");
    auto configs = graphics::GfxConfig({ FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT, FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT });
    graphicsManager->SetConfigs(configs);
    ctx->InitWindowManager();

    cameraManager->SetFovy(45);
    cameraManager->SetCameraProjection(CAMERA_PERSPECTIVE);
    cameraManager->SetCameraPosition({ 20.0f, 20.0f, 20.0f });
    cameraManager->SetCameraTarget({ 10.0f, 10.0f, 10.0f });

    Color cubeColor(50, 150, 250, 255);  // Initial color for cubes
    Color wireframeColor(255, 255, 255, 50);  // Wireframe color
    Color lineColor(255, 255, 255, 100);  // Line color

    const float cubeSize = 0.9f; // Size of each small cube
    const float spacing = 4.0f; // Space between cubes
    const int count = 10; // Number of cubes along each dimension

    // Create cubes
    for (int x = 0; x < count; ++x) {
        for (int y = 0; y < count; ++y) {
            for (int z = 0; z < count; ++z) {
                auto smallCube = Model3DFactory::CreateCube();
                smallCube->SetCenterPos({ x * spacing, y * spacing, z * spacing });
                smallCube->SetColor(cubeColor);
                smallCube->EnableWireframe();
                smallCube->SetWireframeColor(wireframeColor);

                cubes.push_back(smallCube);  // Store the cube in the container
                graphicsManager->AddCube(rand(), smallCube);
            }
        }
    }

    // Connect cubes with lines
    for (int i = 0; i < count * count * count; ++i) {
        auto& cubeA = cubes[i];
        Vector3 posA = cubeA->GetCenterPos();

        // Check neighbors in all 3 dimensions and add lines
        if ((i + 1) % count != 0) {  // Right neighbor
            auto& cubeB = cubes[i + 1];
            Vector3 posB = cubeB->GetCenterPos();

            auto line = Model3DFactory::CreateLine3D(); // Use the factory method
            line->SetStartPos(posA);
            line->SetEndPos(posB);
            lines.push_back(line);
            graphicsManager->AddLine3D(rand(), line);
        }

        if (i + count * count < count * count * count) {  // Front neighbor
            auto& cubeB = cubes[i + count * count];
            Vector3 posB = cubeB->GetCenterPos();

            auto line = Model3DFactory::CreateLine3D(); // Use the factory method
            line->SetStartPos(posA);
            line->SetEndPos(posB);
            lines.push_back(line);
            graphicsManager->AddLine3D(rand(), line);
        }
    }

}

// Default implementation of OnShutdown
void Engine::OnShutdown() {
    std::cout << "Performing engine shutdown tasks..." << std::endl;
}

// Default implementation of OnRender
void Engine::OnRender() {
    std::lock_guard<std::mutex> lock(graphicsMutex); // Lock during rendering
    graphicsManager->Render();
    graphicsManager->Clear(BLACK);
}
