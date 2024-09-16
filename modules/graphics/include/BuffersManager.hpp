#pragma once
#include <memory>
#include "PointBuffer2D.hpp"
#include "LineBuffer2D.hpp"


namespace graphics {

class BuffersManager {
 public:
  BuffersManager();
  std::shared_ptr<PointBuffer2D> GetPointBuffer();
  std::shared_ptr<LineBuffer2D> GetLineBuffer();
 private:
  std::shared_ptr<PointBuffer2D> mPointBuffer;
  std::shared_ptr<LineBuffer2D> mLineBuffer;
  
};

}  // namespace Graphics