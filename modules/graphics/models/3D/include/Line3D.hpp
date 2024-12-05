#ifndef LINE3D_HPP
#define LINE3D_HPP

#include "Model3D.hpp"
#include "raylib.hpp"  // For Vector3 and DrawLine3D

namespace graphics {

    class Line3D : public Model3D {
    public:
        // Constructors
        Line3D();
        Line3D(const raylib::Vector3& start, const raylib::Vector3& end, const raylib::Color& color = raylib::WHITE);

        // Override the draw function
        void Draw() override;

        // Setters
        void SetStartPos(const raylib::Vector3& start);
        void SetEndPos(const raylib::Vector3& end);

        // Getters
        raylib::Vector3 GetStartPos() const;
        raylib::Vector3 GetEndPos() const;


    private:
        raylib::Vector3 mStartPos;  // Starting position of the line
        raylib::Vector3 mEndPos;    // Ending position of the line

    };

}  // namespace graphics

#endif  // LINE3D_HPP
