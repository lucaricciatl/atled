#pragma once
#include <memory>
#include "PointBuffer2D.hpp"
#include "LineBuffer2D.hpp"
#include "PolygonBuffer2D.hpp"

namespace graphics {

class BuffersManager {
 public:
  BuffersManager();
  std::shared_ptr<PointBuffer2D> GetPointBuffer();
  std::shared_ptr<LineBuffer2D> GetLineBuffer();
  std::shared_ptr<PolygonBuffer2D> GetPolygonBuffer();
 private:
  std::shared_ptr<PointBuffer2D> mPointBuffer;
  std::shared_ptr<LineBuffer2D> mLineBuffer;
  std::shared_ptr<PolygonBuffer2D> mPolygonBuffer;
};

}  // namespace Graphics