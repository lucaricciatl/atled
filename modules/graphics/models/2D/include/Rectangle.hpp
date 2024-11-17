#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <vector>

#include "Model2D.hpp"

namespace {
// Rename raylib struct to avoid conflicts
typedef ::Rectangle RectangleStruct;
}  // namespace
namespace graphics {

class Rectangle : public Model,public Model2D {
 private:
  Coordinates2D mUpperLeft;    
  Coordinates2D mBottomRight; 
  ::Color mColor;
  double mRotation;

 public:
  Rectangle(const Coordinates2D& aUpperLeft, const Coordinates2D& aBottomRight);
  Rectangle() = default;

  ::Color GetColor() const;    
  double GetRotation() const;  
  Coordinates2D GetUpperLeft() const;
  Coordinates2D GetBottomRight() const;

  void SetSize(float width, float height);
  void SetPosition(const Coordinates2D& position);
  void SetUpperLeft(const Coordinates2D& aUpperLeft);
  void SetBottomRight(const Coordinates2D& aBottomRight);
  void SetColor(const ::Color& color);  
  void SetRotation(double rotation);    

  void Draw() override;
};

}  // namespace graphics

#endif  // RECTANGLE_HPP