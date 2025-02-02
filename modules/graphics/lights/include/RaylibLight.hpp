#pragma once

#include "Light.hpp"
#include "Vector3.hpp"
#include "raylib.hpp"

struct rLight {
    int type;
    bool enabled;
    math::Vector3 position;
    math::Vector3 target;
    raylib::Color color;
    float attenuation;

    // Shader locations
    int enabledLoc;
    int typeLoc;
    int positionLoc;
    int targetLoc;
    int colorLoc;
    int attenuationLoc = 0;
};

class RaylibLight : public Light
{
public:
    RaylibLight();
    virtual ~RaylibLight();
    rLight CreateLight(int type, math::Vector3 position, math::Vector3 target, raylib::Color color,
                       raylib::Shader shader);

private:
    
};
