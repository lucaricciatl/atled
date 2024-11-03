#ifndef DEFAULTRENDERSTRATEGY_HPP
#define DEFAULTRENDERSTRATEGY_HPP

#include "IRenderStrategy.hpp"
#include "raylib.h"

class DefaultRenderStrategy : public IRenderStrategy {
public:
    void Render(const Model2D& model) const override {
        // Implement default rendering logic
        // Example: DrawPolygon(polygon.GetVertices(), polygon.GetVertexCount(), polygon.GetColor());
    }
};

#endif // DEFAULTRENDERSTRATEGY_HPP
