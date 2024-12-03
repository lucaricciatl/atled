            #version 330
            layout (location = 0) in vec3 vertexPosition;
            layout (location = 1) in vec3 vertexNormal;
            uniform mat4 mvp;
            out vec3 fragNormal;
            void main() {
                fragNormal = vertexNormal;
                gl_Position = mvp * vec4(vertexPosition, 1.0);
            }