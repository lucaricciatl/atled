#include "LayerManager.hpp"
#include <algorithm>
#include <vector>
#include "Layer.hpp"

namespace graphics {

namespace {

LayerId CreateNewId(std::vector<LayerId> ids) {
  std::sort(ids.begin(), ids.end());
  LayerId newId = 0;
  for (LayerId id : ids) {
    if (id == newId) {
      ++newId;
    }
  }
  return newId;
};
}  // namespace

LayerManager::LayerManager() {
    EnableIdReassign(true); }

void LayerManager::EnableIdReassign(bool aIdReassign) {
  mIdReassign = aIdReassign;
};
void LayerManager::AddLayer(const LayerId& id) {
  // Check if the ID already exists
  bool idAlreadyexists = false;
  for (auto& layer : layers) {
    if (layer.GetId() == id) {
      idAlreadyexists = true;
      break;
    }
  }
  LayerId newid = id;
  if (mIdReassign && idAlreadyexists) {
    LayerId newid = CreateNewId(GetLayersIds());
  } else {
    // If the ID is not present, add the new layer
    Layer layer(newid);
    layers.push_back(layer);
  }

}

Layer* LayerManager::GetLayerById(const LayerId& id) {
  for (auto& layer :
       layers) {  // Use non-const to return a pointer to the layer
    if (layer.GetId() == id) {
      return &layer;  // Return a pointer to the found layer
    }
  }
  return nullptr;  // Return nullptr if the layer is not found
}

std::vector<LayerId> LayerManager::GetLayersIds() {
  std::vector<LayerId> layerIds;  // Create a vector to store the IDs
  for (const auto& layer : layers) {
    layerIds.push_back(layer.GetId());  // Add each layer's ID to the vector
  }
  return layerIds;  // Return the vector of IDs
}

// Add a new layer to the vector
void LayerManager::AddLayer(Layer layer) {
  bool idAlreadyexists = false;
  for (const auto& existingLayer : layers) {
    if (existingLayer.GetId() == layer.GetId()) {
      idAlreadyexists = true;
      break;
      }
    }
  if (mIdReassign && idAlreadyexists) {
    LayerId newid = CreateNewId(GetLayersIds());
    layer.SetId(newid);
  } else {
    return;
  }
  layers.push_back(layer);
}

std::vector<Layer> LayerManager::GetLayers() { return layers; };

// Remove a layer by ID
void LayerManager::RemoveLayer(const LayerId& id) {
  auto it =
      std::remove_if(layers.begin(), layers.end(),
                     [id](const Layer& layer) { return layer.GetId() == id; });
  if (it != layers.end()) {
    layers.erase(it, layers.end());
  }
}

}  // namespace graphics
