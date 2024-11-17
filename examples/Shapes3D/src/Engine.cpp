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

using namespace graphics;
using namespace input;


std::mutex graphicsMutex; // Mutex to protect graphicsManager access
bool running = true; // Flag to control the input thread

std::vector<std::shared_ptr<Model3D>> shapes; // To store references to the cubes
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

    for (auto& cube : shapes) {
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

    for (int x = 0; x < count; ++x) {
        for (int y = 0; y < count; ++y) {
            for (int z = 0; z < count; ++z) {
                // Randomly decide whether to create a cube or a sphere
                bool createCube = (rand() % 2 == 0);

                if (createCube) {
                    // Create a cube
                    auto cube = Model3DFactory::CreateCube();
                    cube->SetCenterPos({ x * spacing, y * spacing, z * spacing });
                    cube->SetColor(cubeColor);
                    cube->EnableWireframe();
                    cube->SetWireframeColor(wireframeColor);

                    shapes.push_back(cube);  // Store the cube in the container
                    graphicsManager->AddShape(rand(), cube);
                }
                else {
                    // Create a sphere
                    auto sphere = Model3DFactory::CreateSphere();
                    sphere->SetCenterPos({ x * spacing, y * spacing, z * spacing });
                    sphere->SetRadius(0.5f * spacing); // Set radius relative to spacing
                    sphere->SetColor(cubeColor);
                    sphere->DisableWireframe();

                    sphere->SetRadius(1);                    
                    shapes.push_back(sphere);  // Store the cube in the container
                    graphicsManager->AddShape(rand(), sphere);
                }
            }
        }
    }

    // Connect cubes with lines
    for (int i = 0; i < shapes.size(); ++i) {
        auto& shapeA = shapes[i];

        // Check if the shape is a Cube
        if (auto cubeA = std::dynamic_pointer_cast<Cube>(shapeA)) {
            // Process the Cube
            Vector3 posA = cubeA->GetCenterPos();

            // Example: Connect to neighboring shapes
            if (i + 1 < shapes.size()) {
                auto& shapeB = shapes[i + 1];

                // Check if the neighbor is also a Cube
                if (auto cubeB = std::dynamic_pointer_cast<Cube>(shapeB)) {
                    Vector3 posB = cubeB->GetCenterPos();

                    // Create a line connecting the two cubes
                    auto line = Model3DFactory::CreateLine3D();
                    line->SetStartPos(posA);
                    line->SetEndPos(posB);

                    lines.push_back(line);
                    graphicsManager->AddShape(rand(), line);
                }
                // Check if the neighbor is also a Cube
                if (auto cubeB = std::dynamic_pointer_cast<Sphere>(shapeB)) {
                    Vector3 posB = cubeB->GetCenterPos();

                    // Create a line connecting the two cubes
                    auto line = Model3DFactory::CreateLine3D();
                    line->SetStartPos(posA);
                    line->SetEndPos(posB);

                    lines.push_back(line);
                    graphicsManager->AddShape(rand(), line);
                }
            }
        }
        else if (auto sphereA = std::dynamic_pointer_cast<Sphere>(shapeA)) {
            // Process the Sphere
            Vector3 posA = sphereA->GetCenterPos();

            // Example: Connect to neighboring shapes
            if (i + 1 < shapes.size()) {
                auto& shapeB = shapes[i + 1];
                // Check if the neighbor is also a Cube
                if (auto cubeB = std::dynamic_pointer_cast<Cube>(shapeB)) {
                    Vector3 posB = cubeB->GetCenterPos();

                    // Create a line connecting the two cubes
                    auto line = Model3DFactory::CreateLine3D();
                    line->SetStartPos(posA);
                    line->SetEndPos(posB);

                    lines.push_back(line);
                    graphicsManager->AddShape(rand(), line);
                }
                // Check if the neighbor is also a Cube
                if (auto cubeB = std::dynamic_pointer_cast<Sphere>(shapeB)) {
                    Vector3 posB = cubeB->GetCenterPos();

                    // Create a line connecting the two cubes
                    auto line = Model3DFactory::CreateLine3D();
                    line->SetStartPos(posA);
                    line->SetEndPos(posB);

                    lines.push_back(line);
                    graphicsManager->AddShape(rand(), line);
                }
            }
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
