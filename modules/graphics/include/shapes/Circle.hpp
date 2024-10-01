#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include <vector>

class Circle: public Shape {
private:
    std::vector<double> mCenter; // 2D center (x, y)
    float mRadius;               // Radius of the circle

public:
    // Constructor that accepts a center vector and radius
    Circle(const std::vector<double>& aCenter, const float& aRadius);

    // Getter for radius
    float getRadius() const;

    // Getter for center
    std::vector<double> getCenter() const;

        // Setter for radius with assert
    void setRadius(const float& aRadius);

        // Setter for center with assert
    void setCenter(const std::vector<double>& aCenter);
};

#endif // CIRCLE_HPP
