#include "GraphicsContext.hpp"
#include "ICamera.hpp"
#include "CameraFactory.hpp"
#include <string_view>
#include "WindowFactory.hpp"
#include "RaylibCamera2D.hpp"
#include "RaylibCamera3D.hpp"
#include "glwp.hpp"
#include "GraphicsConfig.hpp"

namespace {
    static constexpr int defaultHeight = 420;
    static constexpr int defaultWidth = 680;
    static constexpr const char* defaultTitle = "Window";
}  // namespace

namespace graphics {

    GraphicsContext::GraphicsContext()
        : windowWidth(defaultWidth),
        windowHeight(defaultHeight),
        windowTitle(defaultTitle) {}

    GraphicsContext::GraphicsContext(int aWindowWidth, int aWindowHeight,
        const char* aWindowTitle,
        std::shared_ptr<GraphicsConfig> flags)
        : windowWidth(aWindowWidth),
        windowHeight(aWindowHeight),
        windowTitle(aWindowTitle) {
        if (flags) {
            for (const auto& flag : flags->WindowConfig) {
                SetFlag(flag);
            }
        }
        InitWindowManager();
    }

    GraphicsContext::GraphicsContext(int aWindowWidth, int aWindowHeight,
        const char* aWindowTitle)
        : windowWidth(aWindowWidth),
        windowHeight(aWindowHeight),
        windowTitle(aWindowTitle) {
        InitWindowManager();
    }

    GraphicsContext::~GraphicsContext() {
        if (mWindow) {
            mWindow->CloseWindow();
        }
    }

    void GraphicsContext::SetFlags(std::shared_ptr<GraphicsConfig> flags) {
        if (flags) {
            for (const auto& flag : flags->WindowConfig) {
                SetFlag(flag);
            }
        }
    }

    void GraphicsContext::InitWindowManager() {
        if (!mWindow) {
            mWindow = WindowFactory::CreateWindow(WindowType::Raylib);
            if (mWindow) {
                mWindow->InitWindow(windowWidth, windowHeight, windowTitle);
            }
        }
    }

    void GraphicsContext::UnsetFlag(ConfigFlags flag) {
        currentFlags &= ~flag;
        ::SetConfigFlags(currentFlags);
    }

    void GraphicsContext::SetFlag(ConfigFlags flag) {
        currentFlags |= flag;
        ::SetConfigFlags(currentFlags);
    }

    void GraphicsContext::SetTitle(const char* title) {
        windowTitle = title;
        if (mWindow) {
            mWindow->SetTitle(windowTitle);
        }
    }

    void GraphicsContext::SetSize(int width, int height) {
        windowWidth = width;
        windowHeight = height;
        if (mWindow) {
            mWindow->SetSize(windowWidth, windowHeight);
        }
    }

    int GraphicsContext::GetWidth() const {
        return windowWidth;
    }

    int GraphicsContext::GetHeight() const {
        return windowHeight;
    }

    void GraphicsContext::BeginDrawing() const {
        ::BeginDrawing();
    }

    void GraphicsContext::EndDrawing() const {
        ::EndDrawing();
    }

    void GraphicsContext::Clear(Color aColor) {
        ::ClearBackground(aColor);
    }

}  // namespace graphics