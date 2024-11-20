#ifndef EVENTBUS_HPP
#define EVENTBUS_HPP

#include <functional>
#include <typeindex>
#include <unordered_map>
#include <vector>
#include "Event.hpp"

class EventBus {
public:
    template <typename EventType>
    void Subscribe(std::function<void(const EventType&)> handler);

    template <typename EventType>
    void Publish(const EventType& event);

private:
    std::unordered_map<std::type_index,
        std::vector<std::function<void(const Event&)>>>
        handlers;
};

template <typename EventType>
void EventBus::Subscribe(std::function<void(const EventType&)> handler) {
    auto& handlersForType = handlers[std::type_index(typeid(EventType))];
    handlersForType.push_back([handler](const Event& event) {
        handler(static_cast<const EventType&>(event));
        });
}

template <typename EventType>
void EventBus::Publish(const EventType& event) {
    auto it = handlers.find(std::type_index(typeid(EventType)));
    if (it != handlers.end()) {
        for (auto& handler : it->second) {
            handler(event);
        }
    }
}


#endif // EVENTBUS_HPP