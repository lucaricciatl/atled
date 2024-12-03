            #version 330
            in vec3 fragNormal;
            uniform vec3 lightColor;
            out vec4 fragColor;
            void main() {
                vec3 norm = normalize(fragNormal);
                vec3 lightDir = normalize(vec3(0.0, 1.0, 1.0)); // Fixed light direction
                float diff = max(dot(norm, lightDir), 0.0);
                fragColor = vec4(diff * lightColor, 1.0);
            }