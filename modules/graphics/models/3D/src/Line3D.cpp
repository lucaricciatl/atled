#include "Line3D.hpp"
#include "Vector3.hpp"
#include "raylib.hpp" // For Vector3 and DrawLine3D
#include "Color.hpp"

namespace graphics
{

    // Default constructor
    Line3D::Line3D()
        : mStartPos({0.0f, 0.0f, 0.0f}),
          mEndPos({1.0f, 1.0f, 1.0f}) {}

    // Parameterized constructor
    Line3D::Line3D(const math::Vector3 &start, const math::Vector3 &end, const Color &color)
        : mStartPos(start), mEndPos(end) {}

    // Override the draw function
    void Line3D::Draw()
    {

        raylib::DrawLine3D(ComputeGlobalPosition(mStartPos), ComputeGlobalPosition(mEndPos), mColor);
    }

    // Setters
    void Line3D::SetStartPos(const math::Vector3 &start)
    {
        mStartPos = start;
    }

    void Line3D::SetEndPos(const math::Vector3 &end)
    {
        mEndPos = end;
    }

    // Getters
    math::Vector3 Line3D::GetStartPos() const
    {
        return mStartPos;
    }

    math::Vector3 Line3D::GetEndPos() const
    {
        return mEndPos;
    }

} // namespace graphics
