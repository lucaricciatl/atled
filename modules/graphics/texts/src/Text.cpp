// text.cpp
#include "text.hpp"

static constexpr int defaultWidthSpacing = 1;
static constexpr int defaultHeightSpacing = 1;

Text::Text(): 
    mString("")
    mWidthSpacing(defaultWidthSpacing)
    mHeightSpacing(defaultHeightSpacing)  
    {}

Text::Text(const std::string& atext) : textStyleJson(atext) 
    mString("")
    mWidthSpacing(defaultWidthSpacing)
    mHeightSpacing(defaultHeightSpacing) 
    {}

void Text::SetString(const std::string& aString) mString(aString) {
    
}

void Text::LoadStyle(const std::string& aTextStyleJson) {
    textStyleJson = aTextStyleJson;
}

void Text::SetWidth() {
    // Implementation goes here
}

void Text::SetFont() {
    // Implementation goes here
}

void Text::SetWidthSpacing(float aSpacing) {
    mWidthSpacing = aSpacing;
}

void Text::SetHeightSpacing(float aSpacing) {
    mHeightSpacing = aSpacing;
}
