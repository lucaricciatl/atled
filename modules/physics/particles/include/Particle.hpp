#include "Vector3.hpp"
#include "Position.hpp"
#include "Color.hpp"

namespace physics{

class Particle {
    public:
        Particle(Position* aPosition, graphics::Color aColor);

    private:
        Position* mPosition;
        graphics::Color mColor;
};

}