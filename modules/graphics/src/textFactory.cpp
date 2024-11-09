#include "textFactory.hpp"

    static ITextDrawer* CreateTextDrawer() {
        // Create and return a new RaylibTextDrawer instance
        return new RaylibTextDrawer();
    }