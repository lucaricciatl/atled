#ifndef ACTIONSYSTEM_HPP
#define ACTIONSYSTEM_HPP

#include "System.hpp"
#include "EventBus.hpp"
#include "InputEvent.hpp"
#include "Action.hpp"
#include "InputBindings.hpp"
#include "IActionHandler.hpp"
#include <vector>
#include <memory>
#include <unordered_map>
#include <mutex>

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

#endif // ACTIONSYSTEM_HPP
