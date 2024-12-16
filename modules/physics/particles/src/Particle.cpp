#include "Particle.hpp"
#include "Position.hpp"

namespace physics{

Particle::Particle(Position* aPosition, graphics::Color aColor):
    mColor(aColor),
    mPosition(aPosition){
}
}