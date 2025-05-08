// text.hpp
#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>

class Text {
public:
    Text();
    Text(const std::string& aString);

    void SetString(const std::string& aString);
    void LoadStyle(const std::string& aTextStyleJson);
    void SetWidth();
    void SetFont();
    void SetWidthSpacing(float aSpacing);
    void SetHeightSpacing(float aSpacing);

private:
    float mWidthSpacing;
    float mWeightSpacing;
    std::string aString;
};

#endif // TEXT_HPP

