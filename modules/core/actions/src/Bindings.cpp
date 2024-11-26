#include "Bindings.hpp"

void Bindings::BindKeyToAction(Key key, Action action) {
    std::lock_guard<std::mutex> lock(bindingsMutex);
    keyToActionsMap[key].push_back(action);
}

void Bindings::UnbindKey(Key key) {
    std::lock_guard<std::mutex> lock(bindingsMutex);
    keyToActionsMap.erase(key);
}

void Bindings::ClearBindings() {
    std::lock_guard<std::mutex> lock(bindingsMutex);
    keyToActionsMap.clear();
}

std::vector<Action> Bindings::GetActionsForKey(Key key) const {
    std::lock_guard<std::mutex> lock(bindingsMutex);
    auto it = keyToActionsMap.find(key);
    if (it != keyToActionsMap.end()) {
        return it->second;
    }
    return {};
}
