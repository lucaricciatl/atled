// LightFactory.h
#pragma once

#include "Light.hpp"
#include "RaylibLight.hpp"
#include "ShaderFactory.hpp"
#include "Color.hpp"
namespace rendering{
enum LightImplType {
    RaylibLightImpl,
};

class LightFactory {
public:
    ~LightFactory(){
    };

    // Create a Light. Arguments can vary depending on your needs.
    static std::shared_ptr<Light> CreateLight(LightImplType aImplType){
        RaylibShaderFactory shaderFactory;
        auto raylibshader = RaylibShader();
        // Corrected version:
        raylibshader.LoadFromFiles("C:\\Users\\atled\\source\\repos\\atled\\modules\\external\\raylib\\examples\\shaders\\resources\\shaders\\glsl120\\lighting.vs",
                      "C:\\Users\\atled\\source\\repos\\atled\\modules\\external\\raylib\\examples\\shaders\\resources\\shaders\\glsl120\\lighting.fs");
                std::string loc = "ambient";
        int ambientLoc = GetShaderLocation(raylibshader.GetShader(), "matModel");
        raylibshader.GetShader().locs[11] = GetShaderLocation(raylibshader.GetShader(), "viewPos");
        float ambientColor[4] = { 0.1f, 0.1f, 0.8f, 1.0f };
        SetShaderValue(raylibshader.GetShader(), ambientLoc, ambientColor, raylib::SHADER_UNIFORM_VEC4);
        auto color = graphics::Color(1.3,0.2,0.1,1);
        auto position = math::Vector3(0.1,4,4); 
        switch (aImplType) {
            case LightImplType::RaylibLightImpl:
                //auto rlight = RaylibLight(raylib::LIGHT_POINT,position,color,raylibshader.GetShader());
                return nullptr;

                // Add more cases here if you have other LightImplType values
                // case LightImplType::someOther:
                //     return new SomeOtherLight();
            default:
                return nullptr;
            };
        }   
    };
}