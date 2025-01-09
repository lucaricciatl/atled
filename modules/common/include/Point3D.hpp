#ifndef POINT3D_HPP
#define POINT3D_HPP

// Simple structure to represent a 3D point
struct Point3D {
    float x;
    float y;
    float z;

    // Constructor with default values
    Point3D(float x_val = 0, float y_val = 0, float z_val = 0) : x(x_val), y(y_val), z(z_val) {}
    // Constructor to cast from Point2D to Point3D
    Point3D(const Point2D& point2D, float z_val = 0) : x(point2D.GetX()), y(point2D.GetY()), z(z_val) {}

    // Getters
    float GetX() const { return x; }

    float GetY() const { return y; }

    float GetZ() const { return z; }

    // Operator: Equality
    bool operator==(const Point3D& other) const { return x == other.x && y == other.y && z == other.z; }

    // Operator: Inequality
    bool operator!=(const Point3D& other) const { return !(*this == other); }

    // Operator: Addition
    Point3D operator+(const Point3D& other) const { return Point3D(x + other.x, y + other.y, z + other.z); }

    // Operator: Subtraction
    Point3D operator-(const Point3D& other) const { return Point3D(x - other.x, y - other.y, z - other.z); }

    // Operator: Scalar Multiplication
    Point3D operator*(float scalar) const { return Point3D(x * scalar, y * scalar, z * scalar); }

    // Operator: Compound Addition
    Point3D& operator+=(const Point3D& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    // Operator: Compound Subtraction
    Point3D& operator-=(const Point3D& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    // Operator: Compound Scalar Multiplication
    Point3D& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    // Operator: Negation (unary minus)
    Point3D operator-() const { return Point3D(-x, -y, -z); }
};

typedef Point3D Coordinates3D;

#endif  // POINT3D_HPP
