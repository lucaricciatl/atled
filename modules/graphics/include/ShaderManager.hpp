#ifndef SHADER_MANAGER_HPP
#define SHADER_MANAGER_HPP

#include <string>
#include <unordered_map>
#include "raylib.h"

class ShaderManager {
public:
    ShaderManager();
    ~ShaderManager();

    // Load shader from files and store it with a name
    bool LoadShader(const std::string& shaderName, const char* vsFileName, const char* fsFileName);

    // Load shader from code strings and store it with a name
    bool LoadShaderFromMemory(const std::string& shaderName, const char* vsCode, const char* fsCode);

    // Check if a shader is ready
    bool IsShaderReady(const std::string& shaderName);

    // Get shader uniform location
    int GetShaderLocation(const std::string& shaderName, const char* uniformName);

    // Get shader attribute location
    int GetShaderLocationAttrib(const std::string& shaderName, const char* attribName);

    // Set shader uniform value
    void SetShaderValue(const std::string& shaderName, int locIndex, const void* value, int uniformType);

    // Set shader uniform value vector
    void SetShaderValueV(const std::string& shaderName, int locIndex, const void* value, int uniformType, int count);

    // Set shader uniform value (matrix 4x4)
    void SetShaderValueMatrix(const std::string& shaderName, int locIndex, Matrix mat);

    // Set shader uniform value for texture (sampler2d)
    void SetShaderValueTexture(const std::string& shaderName, int locIndex, Texture2D texture);

    // Begin custom shader drawing
    void BeginShaderMode(const std::string& shaderName);

    // End custom shader drawing (use default shader)
    void EndShaderMode();

    // Unload shader
    void UnloadShader(const std::string& shaderName);

    // Unload all shaders
    void UnloadAllShaders();

    // Get Shader object
    Shader GetShader(const std::string& shaderName);

private:
    std::unordered_map<std::string, Shader> shaders;
};

#endif // SHADER_MANAGER_HPP
