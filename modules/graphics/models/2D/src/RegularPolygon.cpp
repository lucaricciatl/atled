#include "RegularPolygon.hpp"
#include "raylib.hpp"
#include <cassert>  // For assert


namespace graphics {

// Constructor implementation
RegularPolygon::RegularPolygon(const Coordinates2D& aCenter, int s, double length, double r) 
    : center(aCenter), sides(s), sideLength(length), radius(r) {
    assert(sides >= 3 && "A polygon must have at least 3 sides.");
    assert(sideLength > 0 && "Side length must be greater than 0.");
    assert(radius > 0 && "Radius must be greater than 0.");
}

// Getter implementations
Coordinates2D RegularPolygon::getCenter() const { return center; }
int RegularPolygon::getSides() const { return sides; }
double RegularPolygon::getSideLength() const { return sideLength; }
double RegularPolygon::getRadius() const { return radius; }

// Setter implementations
void RegularPolygon::setCenter(const Coordinates2D& aCenter) { center = aCenter; }
void RegularPolygon::setSides(int s) {
    assert(s >= 3 && "A polygon must have at least 3 sides.");
    sides = s;
}
void RegularPolygon::setSideLength(double length) {
    assert(length > 0 && "Side length must be greater than 0.");
    sideLength = length;
}
void RegularPolygon::setRadius(double r) {
    assert(r > 0 && "Radius must be greater than 0.");
    radius = r;
}

// Drawing the polygon (basic example using trigonometry)
void RegularPolygon::Draw() {
 // Convert Coordinates2D center to raylib's Vector2 type
    Vector2 centerVector = { static_cast<float>(center.x), static_cast<float>(center.y) };

    // Define the polygon's color (assuming a default color here, or pass it via parameters)
    Color polygonColor = { 255, 0, 0, 255 };  // Red color with full opacity

    // Call the DrawPoly function from raylib
    DrawPoly(centerVector, sides, static_cast<float>(radius), 0.0f, polygonColor);
}


}