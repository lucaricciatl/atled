#version 330 core

layout(location = 0) in vec2 vertexPosition;  // Vertex position (x, y)
layout(location = 1) in vec4 vertexColor;     // Vertex color (r, g, b, a)

out vec2 fragPosition;  // Pass to fragment shader
out vec4 fragColor;     // Pass to fragment shader

void main()
{
    // Convert vertex position to normalized device coordinates
    gl_Position = vec4(vertexPosition, 0.0, 1.0);
    fragPosition = vertexPosition;
    fragColor = vertexColor;
}
