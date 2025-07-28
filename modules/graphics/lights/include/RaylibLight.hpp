#pragma once

#include "Light.hpp"
#include "Vector3.hpp"
#include "raylib.hpp"

namespace rendering{

class RaylibLight : public Light
{
public:
    RaylibLight();
    virtual ~RaylibLight();

private:
    
};

}