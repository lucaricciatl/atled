// BuffersManager.hpp

#ifndef BUFFERSMANAGER_HPP
#define BUFFERSMANAGER_HPP

#include <memory>
#include <string>
#include <vector>
#include "Buffer2D.hpp"
#include "Model2D.hpp"
#include "Model2DFactory.hpp"
#include "Arc.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Polygon.hpp"

namespace graphics {

	enum BufferType { 
    SHAPE2D
     };
class BuffersManager {
 public:
  BuffersManager();
  ~BuffersManager();
  std::shared_ptr<Model> createShapeBuffer(const Model2DType type);
  void AddShapeBuffer(std::shared_ptr<Model> aShape);
  std::shared_ptr<Buffer2D> createBuffer(const BufferType type);
  void deleteBuffer(const std::shared_ptr<Buffer2D>& buffer);
  const std::vector<std::shared_ptr<Buffer2D>>& getBuffers();
  const std::vector<std::shared_ptr<Model>>& getShapeBuffers();
  void ClearShapes();

 private:
  std::vector<std::shared_ptr<Buffer2D>> mBuffers;
  std::vector<std::shared_ptr<Model>> mShapeBuffers;
};

}  // namespace graphics

#endif  // BUFFERSMANAGER_HPP
