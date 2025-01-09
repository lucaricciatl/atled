#ifndef ACTIONSYSTEM_HPP
#define ACTIONSYSTEM_HPP

#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

#include "Action.hpp"
#include "EventBus.hpp"
#include "IActionHandler.hpp"
#include "InputBindings.hpp"
#include "InputEvent.hpp"
#include "System.hpp"

class ActionSystem : public System {
   public:
    ActionSystem(EventBus* eventBus, std::shared_ptr<InputBindings> bindings);

    void Init() override;
    void Update(float deltaTime) override;
    void AddActionHandler(std::shared_ptr<IActionHandler> handler);
    void RemoveActionHandler(std::shared_ptr<IActionHandler> handler);

   private:
    void OnInputEvent(const InputEvent& event);

    EventBus* eventBus;
    std::shared_ptr<InputBindings> inputBindings;
    std::vector<std::shared_ptr<IActionHandler>> actionHandlers;
    std::unordered_map<Action, bool> actionStates;
    std::mutex handlersMutex;
};

#endif  // ACTIONSYSTEM_HPP
