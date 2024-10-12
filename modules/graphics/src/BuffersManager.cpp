// BuffersManager.cpp

#include "BuffersManager.hpp"

#include <algorithm>

#include "LineBuffer2D.hpp"
#include "PointBuffer2D.hpp"
#include "PolygonBuffer2D.hpp"
#include "Buffer2D.hpp"
#include "Model2DFactory.hpp"
#include "Model2D.hpp"
namespace graphics {

BuffersManager::BuffersManager() {
  // Constructor implementation
}

BuffersManager::~BuffersManager() {
  // Destructor implementation
  mBuffers.clear();
}


std::shared_ptr<Model2D> BuffersManager::createShapeBuffer(
    const Model2DType type) {
  std::shared_ptr<Model2D> buffer;

  buffer = Model2DFactory::CreateModel2D(type);

  mShapeBuffers.push_back(buffer);
  return buffer;
}

void BuffersManager::AddShapeBuffer(std::shared_ptr<Model2D> aShape) {
  mShapeBuffers.push_back(aShape);
}

std::shared_ptr<Buffer2D> BuffersManager::createBuffer(const BufferType type) {
  std::shared_ptr<Buffer2D> buffer;

  if (type == POINT2D) {
    buffer = std::make_shared<PointBuffer2D>();
  } else if (type == LINE2D) {
    buffer = std::make_shared<LineBuffer2D>();
  } else if (type == POLY2D) {
    buffer = std::make_shared<PolygonBuffer2D>();
  } else {
    // Handle unknown buffer type
    return nullptr;
  }

  mBuffers.push_back(buffer);
  return buffer;
}

void BuffersManager::deleteBuffer(const std::shared_ptr<Buffer2D>& buffer) {
  auto it = std::find(mBuffers.begin(), mBuffers.end(), buffer);
  if (it != mBuffers.end()) {
    mBuffers.erase(it);
  }
}

const std::vector<std::shared_ptr<Buffer2D>>& BuffersManager::getBuffers()
   {
  return mBuffers;
}


const std::vector<std::shared_ptr<Model2D>>& BuffersManager::getShapeBuffers() {
  return mShapeBuffers;
}
}  // namespace graphics
