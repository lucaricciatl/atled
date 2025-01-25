#ifndef POSITION_HPP
#define POSITION_HPP

#include "Vector3.hpp"

namespace physics{

class Position {
private:
    double x, y, z; // Translational components

public:
    // Constructors
    Position();
    Position(double x, double y, double z);
    Position(math::Vector3 position);

    // Destructor
    ~Position();

    // Getters
    double GetX() const;
    double GetY() const;
    double GetZ() const;
    math::Vector3 Get();

    // Setters
    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);
    void Set(double x, double y, double z);
    void Set(math::Vector3 aPos);
    // Transform operations
    void Translate(double dx, double dy, double dz);

    // Operators
    Position operator+(const Position& other) const {
        return Position(x + other.x, y + other.y, z + other.z);
    }

    Position operator-(const Position& other) const {
        return Position(x - other.x, y - other.y, z - other.z);
    }

    Position& operator+=(const Position& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Position& operator-=(const Position& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Position& other) const {
        return !(*this == other);
    }
    
    operator math::Vector3() const {
        return math::Vector3(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z));
    }

    math::Vector3 GetVector3() const {
        return math::Vector3(x, y, z);
    }
};

} // namespace physics

#endif // POSITION_HPP
