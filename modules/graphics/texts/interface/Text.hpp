// text.hpp
#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include "Model.hpp"
#include <Point2D.hpp>
#include "Color.hpp"

namespace graphics {

class Text : public Model {
   public:
    Text();
    Text(std::string aString);

    void SetString(const std::string& aString);
    void LoadStyle(const std::string& aTextStyleJson);
    void SetWidth();
    void SetFont();
    void SetWidthSpacing(float aSpacing);
    void SetHeightSpacing(float aSpacing);
    void Draw() override;
    void SetPosition(Point2D aPosition) { mPosition = aPosition; }
   private:
    float mWidthSpacing;
    float mHeightSpacing;
    std::string mString;
    Point2D mPosition;
    Color mColor;
    int mSize;
};

}  // namespace graphics

#endif // TEXT_HPP

