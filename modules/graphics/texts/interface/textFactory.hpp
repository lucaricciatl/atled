#ifndef TEXTDRAWERFACTORY_HPP
#define TEXTDRAWERFACTORY_HPP

#include "ITextDrawer.hpp"
#include "RaylibtextDrawer.hpp"

namespace graphics {
// Factory class to create instances of TextDrawer
class TextDrawerFactory {
public:
    // Static method to create and return a TextDrawer instance
    static ITextDrawer* CreateTextDrawer();
};

}
#endif // TEXTDRAWERFACTORY_HPP
