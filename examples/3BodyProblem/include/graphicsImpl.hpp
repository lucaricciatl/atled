#include "GraphicsManager.hpp"
#include "Buffer2D.hpp"
#include "PointBuffer2D.hpp"
#include "BuffersManager.hpp"
#include "Layer.hpp"

class GraphicsManagerImpl : public graphics::GraphicsManager {

public :
  void Init() override;
  void Render() override;

  graphics::Layer layer ;
  graphics::Layer layer2 ;
  graphics::BuffersManager bm;
  std::shared_ptr<graphics::Buffer2D> pb;
  std::shared_ptr<graphics::Buffer2D> lb;
  std::shared_ptr<graphics::Buffer2D> polyBuffer ;
  std::shared_ptr<graphics::Buffer2D> polyBuffer2;
    std::shared_ptr<graphics::Buffer2D> polyBuffer3;
};