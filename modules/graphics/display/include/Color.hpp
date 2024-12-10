#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <sstream>
#include <iomanip>

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

private:
    float clamp(float value, float min, float max) const;

    void getRGB255(int &r, int &g, int &b, int &a) const;

    float red;
    float green;
    float blue;
    float alpha;

};

// Non-member function to get a color by name
const Color& getColor(const std::string& name);

// Check if a color exists
bool hasColor(const std::string& name);

// Load the static palette (initialization)
void initializeColorPalette();

};

#endif // COLOR_HPP
