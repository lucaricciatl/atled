#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <memory>
#include <Frame.hpp>
#include "raylib.hpp"

namespace graphics {

raylib::Vector3 toRaylibVector3(math::Vector3 v);
raylib::Color toRaylibColor(const graphics::Color c);

void DrawModel(raylib::Model model, math::Vector3 position, float scale, graphics::Color tint);

void DrawRing(raylib::Vector2 center, float radius, float mThickess, float mStartAngle, int mEndAngle, int segments, graphics::Color tint);

}  // namespace graphics

#endif  // MODEL_HPP
