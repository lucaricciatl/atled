#include <gtest/gtest.h>
#include "GraphicsConfig.hpp"
#include "GraphicsContext.hpp"

namespace {

// Test default GraphicsConfig should initialize with the 4 default flags.
TEST(GraphicsConfigTest, DefaultFlags) {
    graphics::GraphicsConfig cfg;
    ASSERT_EQ(cfg.WindowConfig.size(), 4);
    std::vector<raylib::ConfigFlags> expected = {
        raylib::ConfigFlags::FLAG_VSYNC_HINT,
        raylib::ConfigFlags::FLAG_MSAA_4X_HINT,
        raylib::ConfigFlags::FLAG_WINDOW_HIGHDPI,
        raylib::ConfigFlags::FLAG_WINDOW_RESIZABLE
    };
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(cfg.WindowConfig[i], expected[i]);
    }
}

// Test custom GraphicsConfig flags.
TEST(GraphicsConfigTest, CustomFlags) {
    std::vector<raylib::ConfigFlags> custom = { raylib::ConfigFlags::FLAG_FULLSCREEN_MODE };
    graphics::GraphicsConfig cfg(custom);
    ASSERT_EQ(cfg.WindowConfig.size(), 1);
    EXPECT_EQ(cfg.WindowConfig[0], raylib::ConfigFlags::FLAG_FULLSCREEN_MODE);
}

// Test default GraphicsContext constructor.
TEST(GraphicsContextTest, DefaultConstructor) {
    graphics::GraphicsContext context;
    EXPECT_EQ(context.GetWidth(), 680);
    EXPECT_EQ(context.GetHeight(), 420);
}

// Test updating window size.
TEST(GraphicsContextTest, SetAndGetSize) {
    graphics::GraphicsContext context;
    int newWidth = 1024;
    int newHeight = 768;
    context.SetSize(newWidth, newHeight);
    EXPECT_EQ(context.GetWidth(), newWidth);
    EXPECT_EQ(context.GetHeight(), newHeight);
}

// Test setting the window title.
TEST(GraphicsContextTest, SetTitle) {
    graphics::GraphicsContext context;
    const char* newTitle = "New Window Title";
    EXPECT_NO_THROW(context.SetTitle(newTitle));
}

// Test flag setting and unsetting.
TEST(GraphicsContextTest, SetAndUnsetFlag) {
    graphics::GraphicsContext context;
    // Call SetFlag and UnsetFlag and check that no exceptions/errors occur.
    EXPECT_NO_THROW(context.SetFlag(raylib::ConfigFlags::FLAG_WINDOW_RESIZABLE));
    EXPECT_NO_THROW(context.UnsetFlag(raylib::ConfigFlags::FLAG_WINDOW_RESIZABLE));
}

}  // namespace
