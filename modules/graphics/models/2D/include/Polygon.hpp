#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include "Model2D.hpp"
#include "Triangle.hpp"

namespace graphics {

class Polygon : public Model,public Model2D {
 public:
  // Constructor with parameters
  Polygon(const std::vector<Coordinates2D>& points, const Color& color);
  // Default constructor
  Polygon() = default;

  // Setters and Getters
  void SetPoints(const std::vector<Coordinates2D>& points);
  const std::vector<Coordinates2D>& GetPoints() const;

  // Overridden Draw method
  void Draw() override;

 private:
  std::vector<Coordinates2D> mPoints;

 protected:
  const std::vector<Triangle>  PerformTriangulation();

};

}  // namespace graphics

#endif  // POLYGON_HPP