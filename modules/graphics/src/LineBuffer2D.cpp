#pragma once
#include "LineBuffer2D.hpp"

namespace graphics {


LineBuffer2D::LineBuffer2D() : mLine() {
  // Additional initialization if necessary
}

LineBuffer2D::~LineBuffer2D() = default;

void LineBuffer2D::AddPoint(float x, float y) { mBuffer.emplace_back(x, y); }

ColoredPoint2D LineBuffer2D::GetPoint(size_t aIndex) const {
  if (aIndex < mBuffer.size()) {
    return mBuffer[aIndex];
  }
  return ColoredPoint2D();  // Handle invalid index case, could be enhanced
                            // based on
                     // your logic.
}

void LineBuffer2D::RemovePoint(size_t aIndex) {
  if (aIndex < mBuffer.size()) {
    mBuffer.erase(mBuffer.begin() + aIndex);
  }
}

void LineBuffer2D::ClearBuffer() { mBuffer.clear(); }

size_t LineBuffer2D::GetSize() const { return mBuffer.size(); }

bool LineBuffer2D::IsEmpty() const { return mBuffer.empty(); }

const std::vector<ColoredPoint2D>& LineBuffer2D::GetBuffer() const {
  return mBuffer;
}

void LineBuffer2D::SetBuffer(std::vector<ColoredPoint2D> aBuffer) {
  mBuffer = std::move(aBuffer);  // Move semantics to avoid copying
}

void LineBuffer2D::LoadBuffer() {
  for (const auto& point : mBuffer) {
    mLine.AddPoint(point);
  }
}

void LineBuffer2D::AppendToBuffer(const std::vector<ColoredPoint2D>& aPoints) {
  mBuffer.insert(mBuffer.end(), aPoints.begin(), aPoints.end());
}

void LineBuffer2D::AppendToBuffer(const ColoredPoint2D& aPoint) {
  mBuffer.push_back(aPoint);
}

void LineBuffer2D::DrawBuffer() { 
    mLine.AddPoints(mBuffer);
    mLine.Draw(); 
    mLine.Clear();
}
}  // namespace graphics