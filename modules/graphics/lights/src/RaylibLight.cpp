// RaylibLight.cpp
#include "RaylibLight.hpp"
#include "raylib.hpp"

namespace rendering{
    
RaylibLight::RaylibLight(raylib::LightType lightType, const math::Vector3& position, 
                        graphics::Color color,
                        RaylibShader shader)
{
    //raylib::CreateLight(raylib::LIGHT_POINT, position , math::Vector3(0,0,0), color.toRaylibColor() , shader.GetShader());
}

RaylibLight::RaylibLight()
{
}

RaylibLight::~RaylibLight()
{
    // Destructor implementation (clean up resources if any).
}


}