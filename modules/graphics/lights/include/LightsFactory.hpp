// LightFactory.h
#pragma once

#include "Light.hpp"

enum LightImplType {
    RaylibLightImpl,
};

class LightFactory {
public:
    virtual ~LightFactory() = default;

    // Create a Light. Arguments can vary depending on your needs.
    static Light* CreateLight(LightImplType aImplType);
};