#include "Position.hpp"

namespace physics{

// Default constructor
Position::Position() : x(0.0), y(0.0), z(0.0) {}

// Parameterized constructor
Position::Position(double x, double y, double z) : x(x), y(y), z(z) {}

// Copy constructor
Position::Position(const Position& other) : x(other.x), y(other.y), z(other.z) {}

// Destructor
Position::~Position() {}

// Assignment operator
Position& Position::operator=(const Position& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

// Getters
double Position::getX() const {
    return x;
}

double Position::getY() const {
    return y;
}

double Position::getZ() const {
    return z;
}

// Setters
void Position::setX(double x) {
    this->x = x;
}

void Position::setY(double y) {
    this->y = y;
}

void Position::setZ(double z) {
    this->z = z;
}

void Position::set(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Transform operations
void Position::translate(double dx, double dy, double dz) {
    x += dx;
    y += dy;
    z += dz;
}

} // namespace physics
