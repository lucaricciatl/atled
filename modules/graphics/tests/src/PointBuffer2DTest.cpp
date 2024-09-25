#pragma once
#include "PointBuffer2D.hpp"
#include "gfx-cpp.hpp"
#include "PolyLine2D.hpp"

namespace graphics {

PointBuffer2D::PointBuffer2D() {}

PointBuffer2D::~PointBuffer2D() {}

void PointBuffer2D::addPoint(int x, int y) { buffer.emplace_back(x, y); }

ColoredPoint2D PointBuffer2D::getPoint(size_t index) const {
  if (index < buffer.size()) {
    return buffer[index];
  }
  return Point2D();
}

void PointBuffer2D::removePoint(size_t index) {
  if (index < buffer.size()) {
    buffer.erase(buffer.begin() + index);
  }
}

void PointBuffer2D::clearBuffer() { buffer.clear(); }

size_t PointBuffer2D::getSize() const { return buffer.size(); }

bool PointBuffer2D::isEmpty() const { return buffer.empty(); }

std::vector<ColoredPoint2D> PointBuffer2D::GetBuffer() { return buffer; };

void PointBuffer2D::SetBuffer(std::vector<ColoredPoint2D> aBuffer) {
  buffer = aBuffer;
};

void PointBuffer2D::DrawBuffer(){
  for (auto p : buffer) {
    DrawPixel(p.x, p.y,p.color);
  }
};
}  // namespace graphics