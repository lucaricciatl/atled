#include "Sphere.hpp"
#include "raylib.h"

namespace graphics {

void Sphere::Draw() {
    // Call to Raylib's DrawSphere function to render the sphere
    
    DrawSphere(mCenterPos, mRadius, mColor);
}

}  // namespace graphics
