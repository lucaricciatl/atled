// LightFactory.h
#pragma once

#include "Light.hpp"
#include "RaylibLight.hpp"
#include "ShaderFactory.hpp"
#include "Color.hpp"
#include <memory>
namespace rendering{
enum LightImplType {
    RaylibLightImpl,
};

class LightFactory {
public:
    ~LightFactory(){
    };

    //NB: spostare shader nel graphics manager
    // Create a Light. Arguments can vary depending on your needs.
    static std::shared_ptr<Light> CreateLight(LightImplType aImplType,RaylibShader shader){

        auto color = graphics::Color(1.3,0.2,0.1,1);
        auto position = math::Vector3(0.1,4,4); 
        auto rlight = std::make_shared<RaylibLight>(RaylibLight(raylib::LIGHT_POINT,position,color,shader));
        return rlight;
    };
};
}