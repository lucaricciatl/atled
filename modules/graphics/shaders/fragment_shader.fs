#version 330 core

in vec2 fragPosition;  // From vertex shader
in vec4 fragColor;     // From vertex shader

out vec4 finalColor;

uniform vec2 uCenter;     // Center of the circle (in screen coordinates)
uniform float uRadius;    // Radius of the circle
uniform float uGlowSize;  // Size of the glow effect
uniform vec3 uGlowColor;  // Color of the glow

void main()
{
    // Calculate distance from the fragment to the center
    float distance = length(fragPosition - uCenter);

    // Calculate the alpha based on the distance
    float alpha = 0.0;

    if (distance < uRadius)
    {
        // Inside the circle - fully opaque
        alpha = 1.0;
        finalColor = fragColor;
    }
    else if (distance < uRadius + uGlowSize)
    {
        // Within the glow region - fade out
        alpha = 1.0 - (distance - uRadius) / uGlowSize;
        finalColor = vec4(uGlowColor, alpha);
    }
    else
    {
        // Outside the glow region - fully transparent
        discard;  // Discard the fragment
    }
}
