#include "GraphicsManager.hpp"
#include "Buffer2D.hpp"
#include "PointBuffer2D.hpp"
#include "BuffersManager.hpp"
#include "Layer.hpp"

class GraphicsManagerImpl : public graphics::GraphicsManager {

public :
  void Init() override;
};