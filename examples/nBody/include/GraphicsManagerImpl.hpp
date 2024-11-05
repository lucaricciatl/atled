#pragma once
#include "GraphicsManager.hpp"
#include "NBodySimulation.hpp"

class GraphicsManagerImpl : public graphics::GraphicsManager {
public:
    GraphicsManagerImpl(int numBodies);
    void Init() override;
    void Render() override;

private:
    NBodySimulation simulation;
};
