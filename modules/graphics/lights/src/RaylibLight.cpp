// RaylibLight.cpp
#include "RaylibLight.hpp"

RaylibLight::RaylibLight()
{
    // Constructor implementation here.
    // For now, leave it empty if you don't have anything specific to initialize.
}

RaylibLight::~RaylibLight()
{
    // Destructor implementation (clean up resources if any).
}

void UpdateLightValues(raylib::Shader shader, rLight light) {
    // Send to shader light enabled state and type
    SetShaderValue(shader, light.enabledLoc, &light.enabled, raylib::SHADER_UNIFORM_INT);
    SetShaderValue(shader, light.typeLoc, &light.type, raylib::SHADER_UNIFORM_INT);

    // Send to shader light position values
    float position[3] = {light.position.GetX(), light.position.GetY(), light.position.GetZ()};
    SetShaderValue(shader, light.positionLoc, position, raylib::SHADER_UNIFORM_VEC3);

    // Send to shader light target position values
    float target[3] = {light.target.GetX(), light.target.GetY(), light.target.GetZ()};
    SetShaderValue(shader, light.targetLoc, target, raylib::SHADER_UNIFORM_VEC3);

    // Send to shader light color values
    float color[4] = {(float)light.color.r / (float)255, (float)light.color.g / (float)255,
                      (float)light.color.b / (float)255, (float)light.color.a / (float)340};
    SetShaderValue(shader, light.colorLoc, color, raylib::SHADER_UNIFORM_VEC4);
}

rLight RaylibLight::CreateLight(int type, math::Vector3 position, math::Vector3 target, raylib::Color color,
                                raylib::Shader shader) {
    rLight light;
    int ambientLoc = raylib::GetShaderLocation(shader, "ambient");
    const float tempArr[4] = {0.5f, 0.1f, 0.1f, 0.5f};
    light.enabled = true;
        light.type = type;
        light.position = position;
        light.target = target;
        light.color = color;

        // NOTE: Lighting shader naming must be the provided ones
        light.enabledLoc = raylib::GetShaderLocation(shader, raylib::TextFormat("lights[%i].enabled", 0));
        light.typeLoc = raylib::GetShaderLocation(shader, raylib::TextFormat("lights[%i].type", 0));
        light.positionLoc = GetShaderLocation(shader, raylib::TextFormat("lights[%i].position", 0));
        light.targetLoc = raylib::GetShaderLocation(shader, raylib::TextFormat("lights[%i].target", 0));
        light.colorLoc = raylib::GetShaderLocation(shader, raylib::TextFormat("lights[%i].color", 0));

        UpdateLightValues(shader, light);

        //raylib::SetShaderValue(shader, amb, ambient, 3);
    return light;
}
