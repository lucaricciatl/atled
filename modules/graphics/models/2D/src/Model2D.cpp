#include "Model2D.hpp"
#include <cmath>
#include <numbers>
#include "Color.hpp"
namespace graphics
{

    graphics::Color Model2D::GetColor() const { return mColor; }
    graphics::Color Model2D::GetBorderColor() const { return mBorderColor; }
    double Model2D::GetRotation() const { return mRotation; }
    void Model2D::SetColor(graphics::Color color) { mColor = color; }
    void Model2D::SetRotation(double rotation) { mRotation = rotation; }
    void Model2D::SetDrawBorder(const bool drawborder) { mDrawBorder = drawborder; };
    void Model2D::SetBorderColor(graphics::Color Bordercolor) { mBorderColor = Bordercolor; }
    void Model2D::SetBorderThickness(const int thickness) { mBorderThickness = thickness; };


    } // namespace graphics
