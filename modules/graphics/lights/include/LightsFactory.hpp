// LightFactory.h
#pragma once

#include "Light.hpp"
#include "RaylibLight.hpp"
#include "ShaderFactory.hpp"

enum LightImplType {
    RaylibLightImpl,
};

class LightFactory {
public:
    ~LightFactory(){};

    // Create a Light. Arguments can vary depending on your needs.
    static Light* CreateLight(LightImplType aImplType){
        auto afs= RaylibShaderFactory();
        std::unique_ptr<IShader> shaderPtr = afs.CreateShader();

        RaylibShader* sh = dynamic_cast<RaylibShader*>(shaderPtr.get());

        // Corrected version:
        sh->LoadFromFiles("C:\\Users\\atled\\source\\repos\\atled\\modules\\external\\raylib\\examples\\shaders\\resources\\shaders\\glsl120\\lighting.vs",
                  "C:\\Users\\atled\\source\\repos\\atled\\modules\\external\\raylib\\examples\\shaders\\resources\\shaders\\glsl120\\lighting.fs");
    int ambientLoc = GetShaderLocation(sh->GetShader(), "ambient");
    float ambientColor[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
    SetShaderValue(sh->GetShader(), ambientLoc, ambientColor, raylib::SHADER_UNIFORM_VEC4);
    

    switch (aImplType)
    {
        case LightImplType::RaylibLightImpl:
            
            return new RaylibLight();

        // Add more cases here if you have other LightImplType values
        // case LightImplType::someOther:
        //     return new SomeOtherLight();

        default:
            // In case none of the enums match, return a safe default
            return nullptr;
    }
}
;
};