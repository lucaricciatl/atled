#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

struct Coordinates2D{
    float x,y;
};

class Shape {
 public:
  virtual ~Shape() = default;

};
#endif  // SHAPE_HPP
