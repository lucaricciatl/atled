#ifndef FRAME_HPP
#define FRAME_HPP

#include <memory>
#include <iostream>
#include "Position.hpp"      // Include the Position class
#include "Quaternion.hpp"    // Include the Quaternion class

namespace physics {

    class Frame {
    public:
        // Constructors
        Frame();
        Frame(const std::shared_ptr<Position>& position, const math::Quaternion& orientation);
        Frame(double x, double y, double z, const math::Quaternion& orientation);
        Frame(const Frame& other);
        ~Frame();

        // Assignment operator
        Frame& operator=(const Frame& other);

        // Accessors
        std::shared_ptr<Position> GetPosition() const;
        math::Quaternion GetOrientation() const;

        // Mutators
        void SetPosition(std::shared_ptr<Position>& position);
        void SetPosition(double x, double y, double z);
        void SetOrientation(const math::Quaternion& orientation);

        // Frame operations
        void translate(double dx, double dy, double dz);
        void rotate(const math::Quaternion& rotation);

        // Transformation methods
        void transformPoint(double& px, double& py, double& pz) const;
        void inverseTransformPoint(double& px, double& py, double& pz) const;

        // Friend function for stream insertion
        friend std::ostream& operator<<(std::ostream& os, const Frame& frame);

    private:
        std::shared_ptr<Position> position;
        math::Quaternion orientation;
    };

} // namespace physics

#endif // FRAME_HPP
