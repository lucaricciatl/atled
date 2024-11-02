#ifndef POINT2D_HPP
#define POINT2D_HPP

// Simple structure to represent a 2D point
struct Point2D {
    float x;
    float y;

    Point2D(float x_val = 0, float y_val = 0) : x(x_val), y(y_val) {}

    // Getters
    float GetX() const {
        return x;
    }

    float GetY() const {
        return y;
    }

    // Operator: Equality
    bool operator==(const Point2D& other) const {
        return x == other.x && y == other.y;
    }

    // Operator: Inequality
    bool operator!=(const Point2D& other) const {
        return !(*this == other);
    }

    // Operator: Addition
    Point2D operator+(const Point2D& other) const {
        return Point2D(x + other.x, y + other.y);
    }

    // Operator: Subtraction
    Point2D operator-(const Point2D& other) const {
        return Point2D(x - other.x, y - other.y);
    }

    // Operator: Scalar Multiplication
    Point2D operator*(float scalar) const {
        return Point2D(x * scalar, y * scalar);
    }

    // Operator: Compound Addition
    Point2D& operator+=(const Point2D& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // Operator: Compound Subtraction
    Point2D& operator-=(const Point2D& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    // Operator: Compound Scalar Multiplication
    Point2D& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }


    // Operator: Negation (unary minus)
    Point2D operator-() const {
        return Point2D(-x, -y);
    }

};

typedef Point2D Coordinates2D;

#endif // POINT2D_HPP
