#pragma once

#include <memory>

#include "GuiElement.hpp"  // Ensure the full base class definition is visible
#include "Text.hpp"

namespace gui {

class Label : public GuiElement {
   public:
    // Constructors
    Label();
    // Optionally, constructor with parameters for quick setup:
    Label(const std::string& text, const Coordinates2D& position = {0, 0}, float width = 0, float height = 0);

    virtual ~Label() override = default;

    // Text handling
    void SetText(const std::string& str);
    std::string GetText() const;

    // Override base class virtuals as needed
    void UpdateGeometry() override;
    void UpdateChildren() override;
    void Update(float deltaTime) override;
    void SetPosition(const Coordinates2D& position) override;
    void SetSize(float width, float height) override;
    virtual void Draw() override;
    // Additional label-specific methods if needed

    std::shared_ptr<graphics::Text> mText;
};

}  // namespace gui
