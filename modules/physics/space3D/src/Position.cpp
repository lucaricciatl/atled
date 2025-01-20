#include "Position.hpp"

namespace physics{

// Default constructor
Position::Position() : x(0.0), y(0.0), z(0.0) {}

// Parameterized constructor
Position::Position(double x, double y, double z) : x(x), y(y), z(z) {}

// Destructor
Position::~Position() {}

// Getters
double Position::GetX() const { return x; }

double Position::GetY() const { return y; }

double Position::GetZ() const { return z; }

// Setters
void Position::SetX(double x) { this->x = x; }

void Position::SetY(double y) { this->y = y; }

void Position::SetZ(double z) { this->z = z; }

void Position::Set(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Transform operations
void Position::Translate(double dx, double dy, double dz) {
    x += dx;
    y += dy;
    z += dz;
}

} // namespace physics
