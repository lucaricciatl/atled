// GraphicsManagerFactory.hpp
#pragma once

#include "IGraphicManager.hpp"
#include "GraphicsManager.hpp" // Current concrete implementation
#include <memory>
#include <stdexcept>

namespace graphics {

enum class GraphicsType {
    Default,
    Other
};

class GraphicsManagerFactory {
public:
    static std::unique_ptr<IGraphicManager> CreateGraphicsManager(GraphicsType type) {
        switch (type) {
            case GraphicsType::Default:
                return std::make_unique<GraphicsManager>();
        }
    }
};

} // namespace graphics
