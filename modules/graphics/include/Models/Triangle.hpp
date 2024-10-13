#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <array>
#include "Model2D.hpp"

namespace graphics {

class Triangle : public Model2D {
 public:
  // Constructor with parameters
  Triangle(const Coordinates2D& point1, const Coordinates2D& point2, const Coordinates2D& point3, const Color& color);
  // Default constructor
  Triangle() = default;

  // Setters and Getters
  void SetPoints(const Coordinates2D& point1, const Coordinates2D& point2, const Coordinates2D& point3);
  std::array<Coordinates2D, 3> GetPoints() const;

  void SetColor(const Color& color);
  Color GetColor() const;

  // Overridden Draw method
  void Draw() override;

 private:
  std::array<Coordinates2D, 3> mPoints;
  Color mColor;
};

}  // namespace graphics

#endif  // TRIANGLE_HPP
