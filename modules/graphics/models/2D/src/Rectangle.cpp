#include "Rectangle.hpp"
#include <iostream>
#include <cassert>

namespace
{
    // Rename raylib struct to avoid conflicts
    typedef raylib::Rectangle RectangleStruct;
} // namespace
namespace graphics
{

    Rectangle::Rectangle(const Coordinates2D &aUpperLeft, const Coordinates2D &aBottomRight)
        : mUpperLeft(aUpperLeft), mBottomRight(aBottomRight) {}

    void Rectangle::SetUpperLeft(const Coordinates2D &aUpperLeft)
    {
        mUpperLeft = aUpperLeft;
    }

    void Rectangle::SetBottomRight(const Coordinates2D &aBottomRight)
    {
        mBottomRight = aBottomRight;
    }

    // Implementation of SetSize
    void Rectangle::SetSize(float width, float height)
    {
        assert(width >= 0 && height >= 0 && "Width and height must be non-negative");

        // Update mBottomRight based on mUpperLeft and the new size
        mBottomRight.x = mUpperLeft.x + width;
        mBottomRight.y = mUpperLeft.y + height;
    }

    // Implementation of SetPosition
    void Rectangle::SetPosition(const Coordinates2D &position)
    {
        // Calculate the current size
        float width = mBottomRight.x - mUpperLeft.x;
        float height = mBottomRight.y - mUpperLeft.y;

        // Update mUpperLeft to the new position
        mUpperLeft = position;

        // Update mBottomRight based on the new mUpperLeft and the size
        mBottomRight.x = mUpperLeft.x + width;
        mBottomRight.y = mUpperLeft.y + height;
    }

    Coordinates2D Rectangle::GetUpperLeft() const { return mUpperLeft; }

    Coordinates2D Rectangle::GetBottomRight() const { return mBottomRight; }

    void Rectangle::Draw()
    {
        // Transform the upper-left and bottom-right corners to global positions
        raylib::Vector2 globalUpperLeft = ComputeGlobalPosition(mUpperLeft);
        raylib::Vector2 globalBottomRight = ComputeGlobalPosition(mBottomRight);

        // Calculate the width and height in global space
        float width = globalBottomRight.x - globalUpperLeft.x;
        float height = globalBottomRight.y - globalUpperLeft.y;

        // Ensure the width and height are positive
        if (width < 0 || height < 0)
        {
            // Handle invalid rectangle dimensions (e.g., log a warning or skip drawing)
            return;
        }

        // Define the rectangle in global space
        RectangleStruct rect = {globalUpperLeft.x, globalUpperLeft.y, width, height};

        // Calculate the origin for rotation (center of the rectangle)
        raylib::Vector2 origin = {(rect.width / 2.0f), (rect.height / 2.0f)};

        // Draw the rectangle with transformed global position
        //raylib::DrawRectanglePro(rect, origin, mRotation, mColor);
    }

} // namespace graphics