#include "RegularPolygon.hpp"

#include <cassert>  // For assert


namespace graphics {

// Constructor implementation
RegularPolygon::RegularPolygon(const Coordinates2D& aCenter, int s,
                               double length, double r) : center(aCenter), sides(s), sideLength(length), radius(r) {
  assert(sides >= 3 && "A polygon must have at least 3 sides.");
  assert(sideLength > 0 && "Side length must be greater than 0.");
  assert(radius > 0 && "Radius must be greater than 0.");
}

// Getter for center
Coordinates2D RegularPolygon::getCenter() const { return center; }

// Getter for sides
int RegularPolygon::getSides() const { return sides; }

// Getter for side length
double RegularPolygon::getSideLength() const { return sideLength; }

// Getter for radius
double RegularPolygon::getRadius() const { return radius; }

// Setter for center with validation
void RegularPolygon::setCenter(const Coordinates2D& aCenter) {
  center = aCenter;
}

// Setter for sides with validation
void RegularPolygon::setSides(int s) {
  assert(s >= 3 && "A polygon must have at least 3 sides.");
  sides = s;
}

// Setter for side length with validation
void RegularPolygon::setSideLength(double length) {
  assert(length > 0 && "Side length must be greater than 0.");
  sideLength = length;
}

// Setter for radius with validation
void RegularPolygon::setRadius(double r) {
  assert(r > 0 && "Radius must be greater than 0.");
  radius = r;
}

}