#ifndef LIGHTCOMPONENT_HPP
#define LIGHTCOMPONENT_HPP

#include "Component.hpp"
#include "Light.hpp"
#include "LightsFactory.hpp"  // For createLight(...) and LightImplType
#include <memory>
#include "ServiceProvider.hpp"
#include "Entity.hpp"

class LightComponent : public Component 
{

public:
    LightComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> aServiceProvider)
        : Component(aOwner)
    {
        // Optionally initialize the light
        auto shader = aServiceProvider.get()->GetGraphicManager()->mShader;
        auto mLight = rendering::LightFactory::CreateLight(rendering::LightImplType::RaylibLightImpl,shader);
        if (mLight)
        {


        }
    }

    ~LightComponent() override = default;

    // For demonstration, you might provide an update or render function
    void update()
    {
        // If you want to do something each frame, like rendering:
        if (mLight)
        {
            //mLight->render();
        }
    }

private:
    std::unique_ptr<Light> mLight; 
};

#endif // LIGHTCOMPONENT_HPP
