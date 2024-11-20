#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <typeindex>
#include <unordered_map>

class Entity {
public:
  template <typename ComponentType, typename... Args>
  void AddComponent(Args &&... args);

  template <typename ComponentType> bool HasComponent() const;

  template <typename ComponentType>
  std::shared_ptr<ComponentType> GetComponent();

private:
  std::unordered_map<std::type_index, std::shared_ptr<void>> components;
};

#endif // ENTITY_HPP
