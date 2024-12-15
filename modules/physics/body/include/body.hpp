#pragma once

#include <memory>
#include "Frame.hpp"
#include "Vector3.hpp"

namespace physics {

class Body {
public:
    Body() = default;
    virtual ~Body();
};

} // namespace physics