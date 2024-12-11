#include "Model2D.hpp"
#include <cmath>
#include <numbers>
#include "Color.hpp"
namespace graphics
{

    graphics::Color Model2D::GetColor() const { return mColor; }
    double Model2D::GetRotation() const { return mRotation; }
    void Model2D::SetColor(graphics::Color color) { mColor = color; }
    void Model2D::SetRotation(double rotation) { mRotation = rotation; }

} // namespace graphics
