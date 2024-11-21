#include "textFactory.hpp"

namespace graphics {

static ITextDrawer *CreateTextDrawer() {
  // Create and return a new RaylibTextDrawer instance
  return new RaylibTextDrawer();
    }
    
}