#include "GuiElement.hpp"
#include <algorithm>

namespace gui {

GuiElement::GuiElement() = default;

GuiElement::GuiElement(const Coordinates2D& position, float width, float height)
    : mPosition(position)
    , mWidth(width)
    , mHeight(height) {}

void GuiElement::AddChild(std::shared_ptr<GuiElement> child) {
    if (child) {
        child->SetParent(this);
        mChildren.push_back(child);
    }
}

void GuiElement::RemoveChild(std::shared_ptr<GuiElement> child) {
    if (child) {
        child->SetParent(nullptr);
        mChildren.erase(
            std::remove(mChildren.begin(), mChildren.end(), child),
            mChildren.end()
        );
    }
}

std::vector<std::shared_ptr<GuiElement>> GuiElement::GetChildren() const {
    return mChildren;
}

void GuiElement::SetParent(GuiElement* parent) {
    mParent = parent;
    UpdateGeometry();
}

GuiElement* GuiElement::GetParent() const {
    return mParent;
}

void GuiElement::SetPosition(const Coordinates2D& position) {
    mPosition = position;
    UpdateGeometry();
}

void GuiElement::SetSize(float width, float height) {
    mWidth = width;
    mHeight = height;
    UpdateGeometry();
}

void GuiElement::SetScale(float scale) {
    mScale = scale;
    UpdateGeometry();
}

void GuiElement::SetRotation(float rotation) {
    mRotation = rotation;
    UpdateGeometry();
}

float GuiElement::GetWidth() const {
    return mWidth;
}

float GuiElement::GetHeight() const {
    return mHeight;
}

float GuiElement::GetScale() const {
    return mScale;
}

float GuiElement::GetRotation() const {
    return mRotation;
}

void GuiElement::SetVisible(bool visible) {
    mVisible = visible;
}

bool GuiElement::IsVisible() const {
    return mVisible;
}

void GuiElement::SetStyle(const Style& style) {
    mStyle = style;
    UpdateGeometry();
}

const Style& GuiElement::GetStyle() const {
    return mStyle;
}

Coordinates2D GuiElement::CalculateGlobalPosition() const {
    Coordinates2D globalPos = mPosition;
    const GuiElement* current = mParent;
    
    while (current) {
        //globalPos.x += current->GetPosition().x;
        //globalPos.y += current->GetPosition().y;
        current = current->GetParent();
    }
    
    return globalPos;
}

void GuiElement::UpdateGeometry() {
    // Base implementation updates children
    for (auto& child : mChildren) {
        if (child) {
            child->UpdateGeometry();
        }
    }
}

} // namespace gui
