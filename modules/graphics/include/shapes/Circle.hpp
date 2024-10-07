#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include <vector>


namespace graphics {

class Circle: public Shape {
private:
    Coordinates2D mCenter;       
    float mRadius;               
    Color mColor;

public:

    Circle() = default;
    double GetRadius() const;
    Coordinates2D GetCenter() const;
    void SetColor(Color aColor);
    void SetRadius(const float& aCenter);
    void SetCenter(const Coordinates2D& aCenter);

    void Draw() override ;
};

}
#endif // CIRCLE_HPP
