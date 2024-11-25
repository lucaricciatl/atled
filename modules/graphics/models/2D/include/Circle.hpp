#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "Model2D.hpp"
#include <vector>


namespace graphics {

class Circle: public Model2D {
private:
    Coordinates2D mCenter;       
    float mRadius;               

public:

    Circle() = default;
    double GetRadius() const;
    Coordinates2D GetCenter() const;
    void SetRadius(const float& aCenter);
    void SetCenter(const Coordinates2D& aCenter);

    void Draw() override ;


};

}
#endif // CIRCLE_HPP
