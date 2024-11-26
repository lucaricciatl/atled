#ifndef ACTION_HPP
#define ACTION_HPP

#include "Action.hpp"

enum class Action {
    MoveForward,
    MoveBackward,
    MoveLeft,
    MoveRight,
    Jump,
    Attack,
    // Add other actions as needed
};

class IActionHandler {
public:
    virtual ~IActionHandler() = default;
    virtual void OnAction(Action action, bool activated) = 0;
};

#endif // ACTION_HPP
