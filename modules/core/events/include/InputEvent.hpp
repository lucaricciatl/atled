#ifndef INPUTEVENT_HPP
#define INPUTEVENT_HPP

#include "Event.hpp"
#include "Key.hpp"

class InputEvent : public Event {
   public:
    Key key;  // The key associated with this event

    // Key state flags
    bool pressed;   // True if the key was pressed this frame
    bool released;  // True if the key was released this frame
    bool down;      // True if the key is currently held down
    bool up;        // True if the key is currently not pressed

    // Constructor
    InputEvent(Key key, bool pressed, bool released, bool down, bool up)
        : key(key), pressed(pressed), released(released), down(down), up(up) {}

    // Convenience methods
    bool IsPressed() const { return pressed; }
    bool IsReleased() const { return released; }
    bool IsDown() const { return down; }
    bool IsUp() const { return up; }
};

#endif  // INPUTEVENT_HPP
