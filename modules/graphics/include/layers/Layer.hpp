#pragma once
#include "BuffersManager.hpp"
#include <memory>
#include <vector>

namespace graphics {

typedef int LayerId;
		
class Layer {
 public:
  Layer();
  void Initialize();
  ~Layer();
  Layer(const LayerId& id);
  LayerId GetId() const;
  void SetId(LayerId id );
  std::shared_ptr<BuffersManager> GetBufferManager();
 private:
  LayerId id;
  std::shared_ptr<BuffersManager> mBufferManager;
  
};
}  // namespace graphics