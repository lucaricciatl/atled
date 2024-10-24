#include "GraphicsManager.hpp"
#include "Buffer2D.hpp"
#include "PointBuffer2D.hpp"
#include "BuffersManager.hpp"
#include "Layer.hpp"
#include <vector>
#include "Circle.hpp"
#include "Model2D.hpp"
class GraphicsManagerImpl : public graphics::GraphicsManager {

public :
  void Init() override;
  void Render() override;

};