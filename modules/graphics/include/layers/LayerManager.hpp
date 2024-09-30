#pragma once
#include "Layer.hpp"
#include <vector>


namespace graphics {

class LayerManager {


 public:
  LayerManager();

  std::vector<LayerId> GetLayersIds();
  std::vector<Layer> GetLayers();
  Layer* GetLayerById(const LayerId& id);
  void AddLayer(const LayerId& id);
  void AddLayer(Layer layer);
  void RemoveLayer(const LayerId& id);

  void EnableIdReassign(bool aIdReassign);

 private:

  bool mIdReassign;
  std::vector<Layer>  layers;
};
}  // namespace graphics
