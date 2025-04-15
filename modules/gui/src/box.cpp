#include "Box.hpp"
#include <cassert>

namespace gui {

Box::Box(const Coordinates2D& position, float width, float height)
    : mBackground(std::make_unique<graphics::Rectangle>(position, 
        Coordinates2D(position.x + width, position.y + height)))
    , mCornerRadius(0.0f)
    , mBorderThickness(1.0f)
    , mHasBorder(true)
{
    // Set default colors
    mBackground->SetColor(graphics::Color(0, 0, 0, 1));      // Black background
    mBackground->SetBorderColor(graphics::Color(0, 0, 0, 1));  // Black border
}

void Box::Draw() {
}

void Box::Update(float deltaTime) {
    // Update logic here if needed
}

void Box::SetPosition(const Coordinates2D& position) {
    mBackground->SetPosition(position);
    
}

void Box::SetSize(float width, float height) {
    mBackground->SetSize(width, height);
}

void Box::SetBackgroundColor(const graphics::Color& color) {
    mBackground->SetColor(color);
}

void Box::SetBorderColor(const graphics::Color& color) { mBackground->SetBorderColor(color); }

void Box::SetBorderThickness(float thickness) {
    mBorderThickness = thickness;
    mHasBorder = thickness > 0;
    
    if (mHasBorder) {
        mBackground->SetBorderThickness(thickness);
    }
}

void Box::SetCornerRadius(float radius) {
    mCornerRadius = radius;
}

Coordinates2D Box::GetPosition() const {
    return mBackground->GetUpperLeft();
}

float Box::GetWidth() const {
    return mBackground->GetBottomRight().x - mBackground->GetUpperLeft().x;
}

float Box::GetHeight() const {
    return mBackground->GetBottomRight().y - mBackground->GetUpperLeft().y;
}

graphics::Color Box::GetBackgroundColor() const {
    return mBackground->GetColor();
}

graphics::Color Box::GetBorderColor() const { 
    return mBackground->GetBorderColor(); }

float Box::GetBorderThickness() const {
    return mBorderThickness;
}

float Box::GetCornerRadius() const {
    return mCornerRadius;
}


// Implementation for SetAnchor
void gui::GuiElement::SetAnchor(gui::Anchor anchor) {
    this->mAnchor = anchor;
}

// Implementation for SetZIndex
void gui::GuiElement::SetZIndex(int zIndex) {
    this->mZIndex = zIndex;
}

// Implementation for UpdateLayout
void gui::GuiElement::UpdateLayout() {
    // Basic layout update logic, if any
    mLayoutDirty = false;
    UpdateChildren(); // Ensure child elements are updated
}

// Implementation for SetMinSize
void gui::GuiElement::SetMinSize(float minWidth, float minHeight) {
    mMinWidth = minWidth;
    mMinHeight = minHeight;
}

// Implementation for SetMaxSize
void gui::GuiElement::SetMaxSize(float maxWidth, float maxHeight) {
    mMaxWidth = maxWidth;
    mMaxHeight = maxHeight;
}

// Implementation in Box
void gui::Box::UpdateGeometry() {
    // Geometry update logic specific to Box
}

// Implementation for UpdateChildren
void gui::GuiElement::UpdateChildren() {
    for (auto& child : mChildren) {
        child->UpdateLayout();
    }
}
} // namespace gui