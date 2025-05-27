#include "GuiBoxComponent.hpp"
#include <cassert>
#include "ServiceProvider.hpp"
#include "Text.hpp"

GuiBoxComponent::GuiBoxComponent(Entity* aOwner, std::shared_ptr<ServiceProvider> serviceProvider)
    : Component(aOwner), mServiceProvider(serviceProvider) {
    Init();
}

void GuiBoxComponent::Init() {
    if (!mInitialized) {
        InitializeBox();
        mInitialized = true;
    }
}

void GuiBoxComponent::InitializeBox() {
    // Define initial position and size
    Coordinates2D initialPosition{4.0f, 4.0f};  // Starting at origin
    float initialWidth = 100.0f;                // Default width
    float initialHeight = 100.0f;               // Default height

    // Create box with initial values
    mBox = std::make_unique<gui::Box>(initialPosition, initialWidth, initialHeight);
    mLabel = std::make_unique<gui::Label>();
    // Set default properties
    mBox->SetBackgroundColor(graphics::Color(0.255, 0.255, 0.255, 0.255));  // White
    mBox->SetBorderColor(graphics::Color(0, 0, 0, 0.255));                // Black
    mBox->SetBorderThickness(1.0f);
    mBox->SetSize(100.0f, 100.0f);  // Default size
    mServiceProvider->GetGraphicManager()->AddShape(1, mBox->mBackground);
    mServiceProvider->GetGraphicManager()->AddShape(1, mLabel->mText);

}

void GuiBoxComponent::Update(double aDeltatime) {
    if (mBox) {
        mBox->Update(static_cast<float>(aDeltatime));
    }
}

void GuiBoxComponent::SetPosition(const Coordinates2D& position) {
    if (mBox) {
        mBox->SetPosition(position);
    }
}

void GuiBoxComponent::SetSize(float width, float height) {
    if (mBox) {
        mBox->SetSize(width, height);
    }
}

void GuiBoxComponent::SetBackgroundColor(const graphics::Color& color) {
    if (mBox) {
        mBox->SetBackgroundColor(color);
    }
}

void GuiBoxComponent::SetBorderColor(const graphics::Color& color) {
    if (mBox) {
        mBox->SetBorderColor(color);
    }
}

void GuiBoxComponent::SetBorderThickness(float thickness) {
    if (mBox) {
        mBox->SetBorderThickness(thickness);
    }
}

void GuiBoxComponent::SetCornerRadius(float radius) {
    if (mBox) {
        mBox->SetCornerRadius(radius);
    }
}

void GuiBoxComponent::SetVisible(bool visible) {
    if (mBox) {
        mBox->SetVisible(visible);
    }
}

Coordinates2D GuiBoxComponent::GetPosition() const {
    return mBox ? mBox->GetPosition() : Coordinates2D{0, 0};
}

float GuiBoxComponent::GetWidth() const {
    return mBox ? mBox->GetWidth() : 0.0f;
}

float GuiBoxComponent::GetHeight() const {
    return mBox ? mBox->GetHeight() : 0.0f;
}

graphics::Color GuiBoxComponent::GetBackgroundColor() const {
    return mBox ? mBox->GetBackgroundColor() : graphics::Color{255, 255, 255, 255};
}

graphics::Color GuiBoxComponent::GetBorderColor() const {
    return mBox ? mBox->GetBorderColor() : graphics::Color{0, 0, 0, 255};
}

float GuiBoxComponent::GetBorderThickness() const {
    return mBox ? mBox->GetBorderThickness() : 0.0f;
}

float GuiBoxComponent::GetCornerRadius() const {
    return mBox ? mBox->GetCornerRadius() : 0.0f;
}

bool GuiBoxComponent::IsVisible() const {
    return mBox ? mBox->IsVisible() : false;
}

void GuiBoxComponent::SetText(const std::string& atext) {
    if (mLabel) {
        mLabel->SetText(atext);
        mLabel->SetPosition(GetPosition());
    }
}