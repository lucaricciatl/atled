#include <Entity.hpp>

template <typename ComponentType, typename... Args>
void Entity::AddComponent(Args &&... args) {
  components[typeid(ComponentType)] =
      std::make_shared<ComponentType>(std::forward<Args>(args)...);
}

template <typename ComponentType> bool Entity::HasComponent() const {
  return components.find(typeid(ComponentType)) != components.end();
}

template <typename ComponentType>
std::shared_ptr<ComponentType> Entity::GetComponent() {
  auto it = components.find(typeid(ComponentType));
  if (it != components.end()) {
    return std::static_pointer_cast<ComponentType>(it->second);
  }
  return nullptr;
}
