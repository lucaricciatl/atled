#ifndef GUIBOXCOMPONENT_HPP
#define GUIBOXCOMPONENT_HPP

#include "Component.hpp"
#include "Box.hpp"
#include "Entity.hpp"
#include "Color.hpp"
#include "FrameComponent.hpp"
#include <memory>

class GuiBoxComponent : public Component {
public:
    // Constructor with default owner as nullptr (following Component pattern)
 explicit GuiBoxComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider);
    ~GuiBoxComponent() override = default;

    // Required Component interface methods
    void Init() override;
    void Update(double aDeltatime) override;

    // Box configuration methods
    void SetBackgroundColor(const graphics::Color& aColor);
    void SetBorderColor(const graphics::Color& aColor);
    void SetBorderThickness(float aThickness);
    void SetCornerRadius(float aRadius);
    void SetSize(float aWidth, float aHeight);
    void SetPosition(const Coordinates2D& aPosition);
    void SetVisible(bool visible);
    // Getters
    graphics::Color GetBackgroundColor() const;
    graphics::Color GetBorderColor() const;
    float GetBorderThickness() const;
    float GetCornerRadius() const;
    float GetWidth() const;
    float GetHeight() const;
    Coordinates2D GetPosition() const;

    // Additional functionality
    void Show();
    void Hide();
    bool IsVisible() const;

private:
    std::shared_ptr<ServiceProvider> mServiceProvider;
    std::unique_ptr<gui::Box> mBox;
    bool mInitialized{false};
    bool mVisible{true};

    // Helper method for initialization
    void InitializeBox();
    void UpdateTransform();
};

#endif // GUIBOXCOMPONENT_HPP
