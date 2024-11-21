#ifndef VELOCITY_HPP
#define VELOCITY_HPP

namespace physics{

class Velocity {
private:
    double vx, vy, vz; // Linear velocity components
    double wx, wy, wz; // Angular velocity components

public:
    // Constructors
    Velocity();
    Velocity(double vx, double vy, double vz, double wx, double wy, double wz);

    // Getters
    void getLinearVelocity(double& x, double& y, double& z) const;
    void getAngularVelocity(double& x, double& y, double& z) const;

    // Setters
    void setLinearVelocity(double x, double y, double z);
    void setAngularVelocity(double x, double y, double z);

    // Clear velocities
    void clear();
};

}

#endif // VELOCITY_HPP
