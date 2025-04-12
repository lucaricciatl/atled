#include "Box.hpp"
#include <cassert>

namespace gui {

Box::Box(const Coordinates2D& position, float width, float height)
    : mBackground(std::make_unique<graphics::Rectangle>(position, 
        Coordinates2D(position.x + width, position.y + height)))
    , mBorder(std::make_unique<graphics::Rectangle>(position, 
        Coordinates2D(position.x + width, position.y + height)))
    , mCornerRadius(0.0f)
    , mBorderThickness(1.0f)
    , mHasBorder(false)
{
    // Set default colors
    mBackground->SetColor(graphics::Color(255, 255, 255, 0)); // White background
    mBorder->SetColor(graphics::Color(0, 0, 0, 255));          // Black border
}

void Box::Draw() {
    assert(mBackground && "Background rectangle is null");
    
    // Draw background
    mBackground->Draw();
    
    // Draw border if enabled
    if (mHasBorder && mBorder) {
        mBorder->Draw();
    }
}

void Box::Update(float deltaTime) {
    // Update logic here if needed
}

void Box::SetPosition(const Coordinates2D& position) {
    mBackground->SetPosition(position);
    if (mHasBorder) {
        Coordinates2D borderPos(
            position.x - mBorderThickness,
            position.y - mBorderThickness
        );
        mBorder->SetPosition(borderPos);
    }
}

void Box::SetSize(float width, float height) {
    mBackground->SetSize(width, height);
    if (mHasBorder) {
        mBorder->SetSize(width + 2 * mBorderThickness, height + 2 * mBorderThickness);
    }
}

void Box::SetBackgroundColor(const graphics::Color& color) {
    mBackground->SetColor(color);
}

void Box::SetBorderColor(const graphics::Color& color) {
    mBorder->SetColor(color);
}

void Box::SetBorderThickness(float thickness) {
    mBorderThickness = thickness;
    mHasBorder = thickness > 0;
    
    if (mHasBorder) {
        // Update border size and position
        Coordinates2D currentPos = mBackground->GetUpperLeft();
        float width = mBackground->GetBottomRight().x - currentPos.x;
        float height = mBackground->GetBottomRight().y - currentPos.y;
        
        Coordinates2D borderPos(
            currentPos.x - thickness,
            currentPos.y - thickness
        );
        mBorder->SetPosition(borderPos);
        mBorder->SetSize(width + 2 * thickness, height + 2 * thickness);
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
    return mBorder->GetColor();
}

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