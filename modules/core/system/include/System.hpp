#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <memory>
#include <vector>

class System {
public:
  virtual ~System() = default;
  virtual void Init() {}
  virtual void Update(float deltaTime) {}
  virtual void Shutdown() {}
};

#endif // SYSTEM_HPP
