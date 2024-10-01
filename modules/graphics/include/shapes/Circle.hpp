#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include <vector>


namespace graphics {

class Circle: public Shape {
private:
    Coordinates2D mCenter;       // 2D center (x, y)
    float mRadius;               // Radius of the circle

public:
    // Constructor that accepts a center vector and radius
    Circle(const Coordinates2D& aCenter, const float& aRadius);

    // Getter for radius
    float getRadius() const;

    // Getter for center
    Coordinates2D getCenter() const;

        // Setter for radius with assert
    void setRadius(const float& aRadius);

        // Setter for center with assert
    void setCenter(const Coordinates2D& aCenter);
};

}
#endif // CIRCLE_HPP
