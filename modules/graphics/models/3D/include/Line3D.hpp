#ifndef LINE3D_HPP
#define LINE3D_HPP

#include "Model3D.hpp"
#include "raylib.hpp"  // For Vector3 and DrawLine3D

namespace graphics {


    class Line3D : public Model3D {
    public:
        // Constructors
        Line3D();
        Line3D(const math::Vector3& start, const math::Vector3& end, const raylib::Color& color = raylib::WHITE);

        // Override the draw function
        void Draw() override;

        // Setters
        void SetStartPos(const math::Vector3& start);
        void SetEndPos(const math::Vector3& end);

        // Getters
        math::Vector3 GetStartPos() const;
        math::Vector3 GetEndPos() const;


    private:
        math::Vector3 mStartPos;  // Starting position of the line
        math::Vector3 mEndPos;    // Ending position of the line

    };

}  // namespace graphics

#endif  // LINE3D_HPP
