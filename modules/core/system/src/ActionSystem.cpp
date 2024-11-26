#include "ActionSystem.hpp"

ActionSystem::ActionSystem(EventBus* eventBus, std::shared_ptr<InputBindings> bindings)
    : eventBus(eventBus), inputBindings(bindings) {}

void ActionSystem::Init() {
    eventBus->Subscribe<InputEvent>([this](const InputEvent& event) {
        OnInputEvent(event);
    });
}

void ActionSystem::Update(float deltaTime) {
    // Actions that need per-frame updates can be handled here if necessary.
}

void ActionSystem::AddActionHandler(std::shared_ptr<IActionHandler> handler) {
    std::lock_guard<std::mutex> lock(handlersMutex);
    actionHandlers.push_back(handler);
}

void ActionSystem::RemoveActionHandler(std::shared_ptr<IActionHandler> handler) {
    std::lock_guard<std::mutex> lock(handlersMutex);
    actionHandlers.erase(std::remove(actionHandlers.begin(), actionHandlers.end(), handler), actionHandlers.end());
}

void ActionSystem::OnInputEvent(const InputEvent& event) {
    auto actions = inputBindings->GetActionsForKey(event.key);
    for (const auto& action : actions) {
        bool activated = event.pressed || event.down;
        actionStates[action] = activated;

        // Notify all action handlers
        std::lock_guard<std::mutex> lock(handlersMutex);
        for (const auto& handler : actionHandlers) {
            handler->OnAction(action, activated);
        }
    }
}
