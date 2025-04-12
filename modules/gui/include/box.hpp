#pragma once

#include "GuiElement.hpp"
#include "Rectangle.hpp"
#include "Color.hpp"
#include <memory>

namespace gui {

class Box : public GuiElement {
public:
    // Constructors
    Box() = default;
    Box(const Coordinates2D& position, float width, float height);
    virtual ~Box() = default;

    // IDrawable interface implementation
    void Draw() override;

    // IUpdatable interface implementation
    void Update(float deltaTime) override;

    // Box-specific setters
    void SetBackgroundColor(const graphics::Color& color);
    void SetBorderColor(const graphics::Color& color);
    void SetBorderThickness(float thickness);
    void SetCornerRadius(float radius);

    // Position and size setters (override from GuiElement)
    void SetPosition(const Coordinates2D& position) override;
    void SetSize(float width, float height) override;

    // Getters
    Coordinates2D GetPosition() const;
    float GetWidth() const;
    float GetHeight() const;
    graphics::Color GetBackgroundColor() const;
    graphics::Color GetBorderColor() const;
    float GetBorderThickness() const;
    float GetCornerRadius() const;

protected:
    // Protected utility functions
    void UpdateGeometry() override;

private:
    // Visual components
    std::unique_ptr<graphics::Rectangle> mBackground;
    std::unique_ptr<graphics::Rectangle> mBorder;

    // Box properties
    float mCornerRadius{0.0f};
    float mBorderThickness{1.0f};
    bool mHasBorder{false};
};

// Factory function
std::shared_ptr<Box> CreateBox(
    const Coordinates2D& position = {0, 0},
    float width = 0,
    float height = 0
);

} // namespace gui
