// Engine.hpp
#pragma once

#include "CoreEngine.hpp"
#include <memory>

class Engine : public engine::CoreEngine {
    void EngineLoop() override;  // Overrides the virtual loop from CoreEngine
};

#include "Engine.tpp"
