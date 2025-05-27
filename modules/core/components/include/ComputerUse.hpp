#ifndef COMPUTERUSE_HPP
#define COMPUTERUSE_HPP

#include <Action.hpp>
#include "Component.hpp"
#include <ServiceProvider.hpp>
#include "InputManager.hpp"
#include "GraphicsManager.hpp"

class ComputerUse : public Component {
   public:
    ComputerUse(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
        : Component(aOwner) {
        mGraphicsManager = serviceProvider->GetGraphicManager();
        mInputManager = serviceProvider->GetInputManager();
    };

    void SetupAgentEndopoint(void);
    void Wait(void);
    void StartAction(void);
    void TakeScreenShot(void);
    void SetMousePosition(void);
    void GetMousePosition(void);
    void KeyboardType(void);
    void Mouseclick(void);
    void Respond(void);

   private:
    std::shared_ptr<input::InputManager> mInputManager;
    std::shared_ptr<graphics::IGraphicManager> mGraphicsManager;
};

#endif  // COMPUTERUSE_HPP