#include "BuffersManager.hpp"
#include "LineBuffer2D.hpp"
#include "PointBuffer2D.hpp"


namespace graphics {
BuffersManager::BuffersManager() {
  mPointBuffer = std::make_shared<PointBuffer2D>();
  mLineBuffer = std::make_shared<LineBuffer2D>();
};
std::shared_ptr<PointBuffer2D> BuffersManager::GetPointBuffer() {
  return mPointBuffer;
}
std::shared_ptr<LineBuffer2D> BuffersManager::GetLineBuffer() {
  return mLineBuffer;
};

}  // namespace graphics