// BuffersManager.hpp

#ifndef BUFFERSMANAGER_HPP
#define BUFFERSMANAGER_HPP

#include <memory>
#include <string>
#include <vector>
#include "Buffer2D.hpp"
#include "Shape.hpp"
#include "ShapeFactory.hpp"
#include "Arc.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Polygon.hpp"

namespace graphics {

	enum BufferType { POINT2D, LINE2D, POLY2D, SHAPE2D };
class BuffersManager {
 public:
  BuffersManager();
  ~BuffersManager();
  std::shared_ptr<Shape> createShapeBuffer(const shapeType type);
  void AddShapeBuffer(
      std::shared_ptr<Shape> aShape);
  std::shared_ptr<Buffer2D> createBuffer(const BufferType type);
  void deleteBuffer(const std::shared_ptr<Buffer2D>& buffer);
  const std::vector<std::shared_ptr<Buffer2D>>& getBuffers();
  const std::vector<std::shared_ptr<Shape>>& getShapeBuffers();


 private:
  std::vector<std::shared_ptr<Buffer2D>> mBuffers;
  std::vector<std::shared_ptr<Shape>> mShapeBuffers;
};

}  // namespace graphics

#endif  // BUFFERSMANAGER_HPP
