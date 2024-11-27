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
    double getX() const;
    double getY() const;
    double getZ() const;

    // Setters
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void set(double x, double y, double z);

    // Transform operations
    void translate(double dx, double dy, double dz);
};

} // namespace physics

#endif // POSITION_HPP
