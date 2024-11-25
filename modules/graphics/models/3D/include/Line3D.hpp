#ifndef LINE3D_HPP
#define LINE3D_HPP

#include "Model3D.hpp"
#include "raylib.hpp"  // For Vector3 and DrawLine3D

namespace graphics {

    class Line3D : public Model3D {
    public:
        // Constructors
        Line3D();
        Line3D(const Vector3& start, const Vector3& end, const Color& color = WHITE);

        // Override the draw function
        void Draw() override;

        // Setters
        void SetStartPos(const Vector3& start);
        void SetEndPos(const Vector3& end);

        // Getters
        Vector3 GetStartPos() const;
        Vector3 GetEndPos() const;


    private:
        Vector3 mStartPos;  // Starting position of the line
        Vector3 mEndPos;    // Ending position of the line

    };

}  // namespace graphics

#endif  // LINE3D_HPP
