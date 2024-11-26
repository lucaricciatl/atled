#ifndef INPUTBINDINGS_HPP
#define INPUTBINDINGS_HPP

#include "InputEvent.hpp"
#include "Action.hpp"
#include <unordered_map>
#include <vector>
#include <mutex>

class Bindings {
public:
    void BindKeyToAction(Key key, Action action);
    void UnbindKey(Key key);
    std::vector<Action> GetActionsForKey(Key key) const;
    void ClearBindings();

private:
    mutable std::mutex bindingsMutex;
    std::unordered_map<Key, std::vector<Action>> keyToActionsMap;
};

#endif // INPUTBINDINGS_HPP
