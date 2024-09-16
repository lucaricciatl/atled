#pragma once
#include <vector>
#include "Color.hpp"

namespace graphics {

// Simple structure to represent a 2D point
struct Point2D {
  float x;
  float y;

  Point2D(float x_val = 0, float y_val = 0) : x(x_val), y(y_val) {}
};

struct ColoredPoint2D : Point2D {
  raylib::Color color;

  // Default constructor
  ColoredPoint2D(float x_val = 0, float y_val = 0,
                 raylib::Color clr = raylib::Color())
      : Point2D(x_val, y_val), color(clr) {}

  // Constructor from Point2D
  ColoredPoint2D(const Point2D& pt, raylib::Color clr = raylib::Color())
      : Point2D(pt), color(clr) {}
};


class PointBuffer2D {
 public:
  PointBuffer2D();
  ~PointBuffer2D();
  void addPoint(int x, int y);
  ColoredPoint2D getPoint(size_t index) const;
  std::vector<ColoredPoint2D> GetBuffer();
  void SetBuffer(std::vector<ColoredPoint2D> points);
  void LoadBuffer();
  void removePoint(size_t index);
  void clearBuffer();
  size_t getSize() const;
  bool isEmpty() const;
  void DrawBuffer();

 private:
  std::vector<ColoredPoint2D> buffer;  // A dynamic list of 2D points
};

}  // namespace graphics