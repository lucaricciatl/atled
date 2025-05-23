#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <vector>

#include "Model2D.hpp"

namespace graphics {

class Rectangle : public Model2D {
 private:
  Coordinates2D mUpperLeft;    
  Coordinates2D mBottomRight; 

 public:
  Rectangle(const Coordinates2D& aUpperLeft, const Coordinates2D& aBottomRight);
  Rectangle() = default;

  Coordinates2D GetUpperLeft() const;
  Coordinates2D GetBottomRight() const;

  void SetSize(float width, float height);
  void SetPosition(const Coordinates2D& position);
  void SetUpperLeft(const Coordinates2D& aUpperLeft);
  void SetBottomRight(const Coordinates2D& aBottomRight);
  void SetRoundness(const float& roundness);

  void Draw() override;

 private:
  float mRoundness;
  float mSegments;
};

}  // namespace graphics

#endif  // RECTANGLE_HPP