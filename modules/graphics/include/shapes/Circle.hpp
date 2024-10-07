#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include <vector>


namespace graphics {

class Circle: public Shape {
private:
    Coordinates2D mCenter;       // 2D center (x, y)
    float mRadius;               // Radius of the circle
    Color mColor;

public:

    Circle() = default;
    // Getter for radius
    double getRadius() const;

    // Getter for center
    Coordinates2D getCenter() const;
    void setColor(Color aColor);
    void SetRadius(const float& aCenter);

        // Setter for center with assert
    void setCenter(const Coordinates2D& aCenter);

    void Draw() override ;
};

}
#endif // CIRCLE_HPP
