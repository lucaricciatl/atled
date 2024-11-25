// GraphicsManagerFactory.hpp
#pragma once

#include "IGraphicManager.hpp"
#include "GraphicsManager.hpp" // Current concrete implementation
#include <memory>
#include <stdexcept>

namespace graphics {

enum class GraphicsType {
    Invalid,
    Raylib
};

class GraphicsManagerFactory {
public:
    static std::unique_ptr<IGraphicManager> CreateGraphicsManager(GraphicsType type) {
        switch (type) {
            case GraphicsType::Raylib:
                return std::make_unique<GraphicsManager>();
            default:
                return nullptr;
        }
    }
};

} // namespace graphics
