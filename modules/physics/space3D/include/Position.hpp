#ifndef POSITION_HPP
#define POSITION_HPP

namespace physics{

class Position {
private:
    double x, y, z; // Translational components

public:
    // Constructors
    Position();
    Position(double x, double y, double z);

    // Destructor
    ~Position();

    // Getters
    double GetX() const;
    double GetY() const;
    double GetZ() const;

    // Setters
    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);
    void Set(double x, double y, double z);

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
};

} // namespace physics

#endif // POSITION_HPP
