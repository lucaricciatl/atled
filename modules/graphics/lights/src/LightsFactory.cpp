#include "LightsFactory.hpp"
#include "RaylibLight.hpp"

Light* createLight(LightImplType aImplType)
{
    switch (aImplType)
    {
        case LightImplType::RaylibLightImpl:
            // Return some implementation of the Light interface
            // e.g., return new RaylibLight();
            return new RaylibLight();

        // Add more cases here if you have other LightImplType values
        // case LightImplType::someOther:
        //     return new SomeOtherLight();

        default:
            // In case none of the enums match, return a safe default
            return nullptr;
    }
}
