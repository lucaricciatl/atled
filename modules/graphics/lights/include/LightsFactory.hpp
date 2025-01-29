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
        auto sh = afs.CreateShader();
        // Corrected version:
        sh->LoadFromFiles("C:\\Users\\atled\\source\\repos\\atled\\modules\\external\\raylib\\examples\\shaders\\resources\\shaders\\glsl120\\lighting.fs",
                  "C:\\Users\\atled\\source\\repos\\atled\\modules\\external\\raylib\\examples\\shaders\\resources\\shaders\\glsl120\\base.vs");
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