#pragma once

#include "Light.hpp"
#include "Vector3.hpp"
#include "raylib.hpp"
#include "raylibShader.hpp"
#include "Color.hpp"

namespace rendering{

class RaylibLight : public Light
{
public:
    RaylibLight(raylib::LightType lightType, const math::Vector3& position, 
                        graphics::Color color,
                        RaylibShader shader);
    RaylibLight();

    ~RaylibLight();

private:
    raylib::Light mLight;
};

}