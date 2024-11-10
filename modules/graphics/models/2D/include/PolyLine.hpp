#ifndef POLYLINE_HPP
#define POLYLINE_HPP

#include <vector>
#include "Model2D.hpp"

namespace graphics {

class Polyline : public Model {
 public:
  // Constructor with parameters
  Polyline(const std::vector<Coordinates2D>& points, double thickness, const Color& color);
  // Default constructor
  Polyline() = default;

  // Setters and Getters
  void SetPoints(const std::vector<Coordinates2D>& points);
  const std::vector<Coordinates2D>& GetPoints() const;

  void SetThickness(double thickness);
  double GetThickness() const;

  void SetColor(const Color& color);
  Color GetColor() const;

  // Overridden Draw method
  void Draw() override;

 private:
  std::vector<Coordinates2D> mPoints;
  double mThickness;
  Color mColor;
};

}  // namespace graphics

#endif  // POLYLINE_HPP