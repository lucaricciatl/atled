#pragma once
#include <vector>
#include "Buffer2D.hpp"
#include <vector>
#include "glwp.hpp"

namespace graphics {

// Simple structure to represent a 2D point
struct Point2D {
    float x;
    float y;

    Point2D(float x_val = 0, float y_val = 0) : x(x_val), y(y_val) {}

    // Getters
    float GetX() const {
        return x;
    }

    float GetY() const {
        return y;
    }

    // Operator: Equality
    bool operator==(const Point2D& other) const {
        return x == other.x && y == other.y;
    }

    // Operator: Inequality
    bool operator!=(const Point2D& other) const {
        return !(*this == other);
    }

    // Operator: Addition
    Point2D operator+(const Point2D& other) const {
        return Point2D(x + other.x, y + other.y);
    }

    // Operator: Subtraction
    Point2D operator-(const Point2D& other) const {
        return Point2D(x - other.x, y - other.y);
    }

    // Operator: Scalar Multiplication
    Point2D operator*(float scalar) const {
        return Point2D(x * scalar, y * scalar);
    }

    // Operator: Compound Addition
    Point2D& operator+=(const Point2D& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // Operator: Compound Subtraction
    Point2D& operator-=(const Point2D& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    // Operator: Compound Scalar Multiplication
    Point2D& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }


    // Operator: Negation (unary minus)
    Point2D operator-() const {
        return Point2D(-x, -y);
    }

};


typedef Point2D Coordinates2D;


struct ColoredPoint2D : Point2D {
  glwp::Color color;  // Assuming Color is a global type

  // Default constructor
  ColoredPoint2D(float x_val = 0, float y_val = 0,
                 glwp::Color clr = glwp::Color())
      : Point2D(x_val, y_val), color(clr) {}

  // Constructor from Point2D
  ColoredPoint2D(const Point2D& pt, glwp::Color clr = glwp::Color())
      : Point2D(pt), color(clr) {}

};



class PointBuffer2D : public Buffer2D {
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
  void DrawBuffer() ;

 private:
  std::vector<ColoredPoint2D> buffer;  // A dynamic list of 2D points
};

}  // namespace graphics