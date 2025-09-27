#include "Text.hpp"
#include "Color.hpp"

namespace graphics {
constexpr int defaultWidthSpacing = 1;
constexpr int defaultHeightSpacing = 1;
constexpr int defaultSize = 12;
const Color defaultColor = Color(1, 1, 1, 1);

    // Default constructor
Text::Text()
    : mString(""),
      mWidthSpacing(defaultWidthSpacing),
      mHeightSpacing(defaultHeightSpacing),
      mColor(defaultColor),
      mSize(defaultSize) {}

// Constructor with style JSON input (assuming aText is a style JSON string)
Text::Text(std::string aString)
    : mString(aString),
      mWidthSpacing(defaultWidthSpacing),
      mHeightSpacing(defaultHeightSpacing),
      mColor(defaultColor),
      mSize(defaultSize) {}

// Sets the text string
void Text::SetString(const std::string& aString) { mString = aString; }

// Loads the style JSON string
void Text::LoadStyle(const std::string& aTextStyleJson) {
    // Optionally, parse the JSON here to set additional style properties
}

// Placeholder for width-related logic
void Text::SetWidth() {
    // Implementation goes here
}

// Placeholder for font-related logic
void Text::SetFont() {
    // Implementation goes here
}

// Sets the spacing between characters horizontally
void Text::SetWidthSpacing(float aSpacing) { mWidthSpacing = aSpacing; }

// Sets the spacing between lines vertically
void Text::SetHeightSpacing(float aSpacing) { mHeightSpacing = aSpacing; }

void Text::Draw() { 
    raylib::DrawText(mString.c_str(), mPosition.GetX(), mPosition.GetY(), mSize, mColor.toRaylibColor());
};
}  // namespace Graphics