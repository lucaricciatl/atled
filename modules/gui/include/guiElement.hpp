#pragma once

#include "Color.hpp"
#include "Frame.hpp"
#include <memory>
#include <vector>
#include <functional>
#include <string>
#include "Point2D.hpp"

namespace gui {

// Forward declarations
class GuiElement;
using GuiElementPtr = std::shared_ptr<GuiElement>;
using GuiElementWeakPtr = std::weak_ptr<GuiElement>;

// Interface for drawable elements
class IDrawable {
public:
    virtual ~IDrawable() = default;
    virtual void Draw() = 0;
};

// Interface for updatable elements
class IUpdatable {
public:
    virtual ~IUpdatable() = default;
    virtual void Update(float deltaTime) = 0;
};

// Interface for interactive elements
class IInteractable {
public:
    virtual ~IInteractable() = default;
    virtual bool IsHovered() const = 0;
    virtual bool IsPressed() const = 0;
    virtual bool IsFocused() const = 0;
    virtual bool IsEnabled() const = 0;
    
    virtual void SetEnabled(bool enabled) = 0;
    virtual void SetFocused(bool focused) = 0;
    
    virtual void OnHover(std::function<void()> callback) = 0;
    virtual void OnLeave(std::function<void()> callback) = 0;
    virtual void OnPress(std::function<void()> callback) = 0;
    virtual void OnRelease(std::function<void()> callback) = 0;
    virtual void OnFocus(std::function<void()> callback) = 0;
    virtual void OnBlur(std::function<void()> callback) = 0;
};

// Anchor points for element positioning
enum class Anchor {
    TopLeft,
    TopCenter,
    TopRight,
    CenterLeft,
    Center,
    CenterRight,
    BottomLeft,
    BottomCenter,
    BottomRight
};

// Style properties
struct Style {
    graphics::Color backgroundColor{255, 255, 255, 255};
    graphics::Color borderColor{0, 0, 0, 255};
    graphics::Color hoverColor{245, 245, 245, 255};
    graphics::Color pressColor{235, 235, 235, 255};
    graphics::Color disabledColor{200, 200, 200, 255};
    float borderThickness{1.0f};
    float cornerRadius{0.0f};
    float padding{0.0f};
    float margin{0.0f};
    bool visible{true};
    bool enabled{true};
};

class GuiElement : public IDrawable, public IUpdatable {
public:
    // Constructors
    GuiElement();
    GuiElement(const std::string& name);
    GuiElement(const Coordinates2D& position, float width, float height);
    virtual ~GuiElement() = default;

    // Hierarchy management
    void AddChild(GuiElementPtr child);
    void RemoveChild(GuiElementPtr child);
    void RemoveAllChildren();
    std::vector<GuiElementPtr> GetChildren() const;
    void SetParent(GuiElement* parent);
    GuiElement* GetParent() const;
    bool HasChild(const GuiElementPtr& child) const;
    Coordinates2D CalculateGlobalPosition() const;
    // Element properties
    void SetName(const std::string& name);
    std::string GetName() const;
    
    // Transform operations
    virtual void SetPosition(const Coordinates2D& position);
    virtual void SetSize(float width, float height);
    virtual void SetScale(float scale);
    virtual void SetRotation(float rotation);
    virtual void SetAnchor(Anchor anchor);
    virtual void SetZIndex(int zIndex);
    // Getters for transform properties
    float GetWidth() const;
    float GetHeight() const;
    float GetScale() const;
    float GetRotation() const;
    Coordinates2D GetPosition();
    Anchor GetAnchor() const;
    int GetZIndex() const;
    bool mVisible;

    // Style operations
    virtual void SetStyle(const Style& style);
    const Style& GetStyle() const;
    void SetVisible(bool visible);
    bool IsVisible() const;
    
    // Frame component access
    std::shared_ptr<physics::Frame> GetFrame() const;
    
    // Layout operations
    virtual void UpdateLayout();
    virtual void SetMinSize(float minWidth, float minHeight);
    virtual void SetMaxSize(float maxWidth, float maxHeight);
    
    // Utility functions
    bool ContainsPoint(const Coordinates2D& point) const;
    GuiElementPtr FindElementAt(const Coordinates2D& point);
    void BringToFront();
    void SendToBack();

protected:
    virtual void UpdateGeometry();
    virtual void UpdateChildren();
    
    // Protected member variables
    std::string mName;
    Coordinates2D mPosition{0, 0};
    float mWidth{0};
    float mHeight{0};
    float mMinWidth{0};
    float mMinHeight{0};
    float mMaxWidth{std::numeric_limits<float>::max()};
    float mMaxHeight{std::numeric_limits<float>::max()};
    float mScale{1.0f};
    float mRotation{0};
    Anchor mAnchor{Anchor::TopLeft};
    int mZIndex{0};
    Style mStyle;
    
    GuiElement* mParent{nullptr};
    std::vector<GuiElementPtr> mChildren;
    std::shared_ptr<physics::Frame> mFrame;
    
    bool mNeedsUpdate{true};
    bool mLayoutDirty{true};

private:
    void Initialize();
    void SortChildren();
};

// Factory function
GuiElementPtr CreateGuiElement(const std::string& name = "",
                             const Coordinates2D& position = {0, 0},
                             float width = 0,
                             float height = 0);

} // namespace gui
