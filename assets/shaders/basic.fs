#version 330
in vec2 fragTexCoord;
out vec4 finalColor;

uniform sampler2D texture0;

void main() {
    vec4 color = texture(texture0, fragTexCoord);
    float brightness = (color.r + color.g + color.b) / 3.0;
    if (brightness > 0.5) {
        finalColor = color;
    } else {
        finalColor = vec4(0.0);
    }
}
