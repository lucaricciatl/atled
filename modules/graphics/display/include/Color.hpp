#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <sstream>
#include <iomanip>
#include <raylib.hpp>

namespace graphics {

class Color {
public:
    // Constructors
    Color(); // Default constructor (black)
    Color(float r, float g, float b, float a = 1.0f); // Constructor with RGBA values

    // Getters
    float getRed() const;
    float getGreen() const;
    float getBlue() const;
    float getAlpha() const;

    // Setters
    void setRed(float r);
    void setGreen(float g);
    void setBlue(float b);
    void setAlpha(float a);

    // Utility Methods
    std::string toHex() const; // Converts to hexadecimal format
    void fromHex(const std::string& hex); // Sets color from hexadecimal string

    bool operator==(const Color& other) const;
    bool operator!=(const Color& other) const;
    raylib::Color toRaylibColor() const; // Converts to Raylib's Color
    static Color fromRaylibColor(const raylib::Color& rayColor); // Creates from Raylib's Color

private:
    float clamp(float value, float min, float max) const;

    void getRGB255(int &r, int &g, int &b, int &a) const;

    float red;
    float green;
    float blue;
    float alpha;

};

raylib::Color toRaylibColor(const Color& color);
Color fromRaylibColor(const raylib::Color& rayColor);

};
#endif // COLOR_HPP
