#include "model.hpp"
#include "raylib.hpp"

namespace graphics{
    raylib::Vector3 toRaylibVector3(math::Vector3 v){return {v.getX(),v.getY(),v.getZ()};}
    
    raylib::Color toRaylibColor(const graphics::Color c) {
        int r = c.getRed() * 255;
        int g = c.getGreen() * 255;
        int b = c.getBlue() * 255;
        int a =c.getAlpha() * 255;
        raylib::Color color = { r,g,b,a};
        return color;
    }

    void DrawModel(raylib::Model model, math::Vector3 position, float scale, graphics::Color tint){
        raylib::DrawModel(model, toRaylibVector3(position), scale, toRaylibColor(tint));
    }

    void DrawRing(raylib::Vector2 center, float radius, float mThickess, float mStartAngle, int mEndAngle, int segments, graphics::Color tint) {
        raylib::DrawRing(center, radius - mThickess, radius + mThickess,
                     mStartAngle, mEndAngle, segments, toRaylibColor(tint));
    }



}