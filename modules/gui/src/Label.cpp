#include "Label.hpp"
#include <iostream>

namespace gui {

// Default constructor
Label::Label() : mText(std::make_shared<graphics::Text>()) {
    // Any additional initialization if needed
}

// Optional constructor with text, position, width, height
Label::Label(const std::string& text, const Coordinates2D& position, float width, float height)
    : GuiElement(position, width, height),
      mText(std::make_shared<graphics::Text>())
{
    SetText(text);
}

// Set the label's text content
void Label::SetText(const std::string& text) {
    if (mText) {
        mText->SetString(text);
    }
}

// Updates the label state - dummy body
void Label::Update(float /*deltaTime*/) {
    // Example: Mark as needing update or perform time-based logic
    mNeedsUpdate = false;
    // std::cout << "Label::Update called" << std::endl;
}

// Sets the label's position
void Label::SetPosition(const Coordinates2D& position) {
    mPosition = position;
    if (mText) {
        mText->SetPosition(position);
    }
}

// Sets the label's size
void Label::SetSize(float width, float height) {
    mWidth  = width;
    mHeight = height;
    // Update text bounds/layout if necessary
    // std::cout << "Label::SetSize called" << std::endl;
}

// Updates the label's layout geometry
void Label::UpdateGeometry() {
    // Recompute geometry, e.g., for rendering text in bounds
    // std::cout << "Label::UpdateGeometry called" << std::endl;
}

// Updates children - for a label this may be empty
void Label::UpdateChildren() {
    // Label likely has no children, but method required by base class
    // std::cout << "Label::UpdateChildren called" << std::endl;
}

void Label::Draw() {
    // Label likely has no children, but method required by base class
    // std::cout << "Label::UpdateChildren called" << std::endl;
}

} // namespace gui
