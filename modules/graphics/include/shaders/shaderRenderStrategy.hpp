#ifndef SHADERRENDERSTRATEGY_HPP
#define SHADERRENDERSTRATEGY_HPP

#include "IRenderStrategy.hpp"
#include "Polygon.hpp"
#include "raylib.h"

class ShaderRenderStrategy : public IRenderStrategy {
public:
    explicit ShaderRenderStrategy(const Shader& shader) : shader(shader) {}

    void Render(const Polygon& polygon) const override {
        BeginShaderMode(shader);
        // Implement shader-based rendering logic
        // Example: DrawPolygon(polygon.GetVertices(), polygon.GetVertexCount(), polygon.GetColor());
        EndShaderMode();
    }

private:
    Shader shader;
};

#endif // SHADERRENDERSTRATEGY_HPP
