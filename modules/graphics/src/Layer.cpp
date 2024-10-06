#include "Layer.hpp"

#include "BuffersManager.hpp"
#include "LayerManager.hpp"

namespace graphics {

void Layer::Initialize() { mBufferManager = std::make_shared<BuffersManager>(); };

Layer::Layer() { Initialize(); }

Layer::~Layer(){};

Layer::Layer(const LayerId& id) : id(id) { Initialize(); }

LayerId Layer::GetId() const { return id; }

void Layer::SetId(LayerId aId) { id = aId; };

std::shared_ptr<BuffersManager> Layer::GetBufferManager() {
  return mBufferManager;
};

void Layer::Draw() {
  auto shapes = mBufferManager->getShapeBuffers();
  for (auto shape : shapes) {
    shape->Draw();
  };
}
}  // namespace graphics