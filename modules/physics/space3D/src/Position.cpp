#include "Position.hpp"

namespace physics{

// Default constructor
Position::Position() : x(0.0), y(0.0), z(0.0) {}

// Parameterized constructor
Position::Position(double x, double y, double z) : x(x), y(y), z(z) {}

Position::Position(math::Vector3 position) : x(position.GetX()), y(position.GetY()), z(position.GetZ()) {}

// Destructor
Position::~Position() {}

// Getters
double Position::GetX() const { return x; }

double Position::GetY() const { return y; }

double Position::GetZ() const { return z; }

math::Vector3 Position::Get() { return math::Vector3(x, y, z); }

// Setters
void Position::SetX(double x) { this->x = x; }

void Position::SetY(double y) { this->y = y; }

void Position::SetZ(double z) { this->z = z; }

void Position::Set(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Position::Set(math::Vector3 aPos) {
    this->x = aPos.GetX();
    this->y = aPos.GetY();
    this->z = aPos.GetZ();
}

// Transform operations
void Position::Translate(double dx, double dy, double dz) {
    x += dx;
    y += dy;
    z += dz;
}

} // namespace physics
