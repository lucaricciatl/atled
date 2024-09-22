#include "ShaderManager.hpp"

ShaderManager::ShaderManager() {
    // Constructor
}

ShaderManager::~ShaderManager() {
    UnloadAllShaders();
}

bool ShaderManager::LoadShader(const std::string& shaderName, const char* vsFileName, const char* fsFileName) {
    Shader shader = ::LoadShader(vsFileName, fsFileName);
    if (::IsShaderReady(shader)) {
        shaders[shaderName] = shader;
        return true;
    }
    return false;
}

bool ShaderManager::LoadShaderFromMemory(const std::string& shaderName, const char* vsCode, const char* fsCode) {
    Shader shader = ::LoadShaderFromMemory(vsCode, fsCode);
    if (::IsShaderReady(shader)) {
        shaders[shaderName] = shader;
        return true;
    }
    return false;
}

bool ShaderManager::IsShaderReady(const std::string& shaderName) {
    auto it = shaders.find(shaderName);
    return it != shaders.end() && ::IsShaderReady(it->second);
}

int ShaderManager::GetShaderLocation(const std::string& shaderName, const char* uniformName) {
    auto it = shaders.find(shaderName);
    if (it != shaders.end()) {
        return ::GetShaderLocation(it->second, uniformName);
    }
    return -1;
}

int ShaderManager::GetShaderLocationAttrib(const std::string& shaderName, const char* attribName) {
    auto it = shaders.find(shaderName);
    if (it != shaders.end()) {
        return ::GetShaderLocationAttrib(it->second, attribName);
    }
    return -1;
}

void ShaderManager::SetShaderValue(const std::string& shaderName, int locIndex, const void* value, int uniformType) {
    auto it = shaders.find(shaderName);
    if (it != shaders.end()) {
        ::SetShaderValue(it->second, locIndex, value, uniformType);
    }
}

void ShaderManager::SetShaderValueV(const std::string& shaderName, int locIndex, const void* value, int uniformType, int count) {
    auto it = shaders.find(shaderName);
    if (it != shaders.end()) {
        ::SetShaderValueV(it->second, locIndex, value, uniformType, count);
    }
}

void ShaderManager::SetShaderValueMatrix(const std::string& shaderName, int locIndex, Matrix mat) {
    auto it = shaders.find(shaderName);
    if (it != shaders.end()) {
        ::SetShaderValueMatrix(it->second, locIndex, mat);
    }
}

void ShaderManager::SetShaderValueTexture(const std::string& shaderName, int locIndex, Texture2D texture) {
    auto it = shaders.find(shaderName);
    if (it != shaders.end()) {
        ::SetShaderValueTexture(it->second, locIndex, texture);
    }
}

void ShaderManager::BeginShaderMode(const std::string& shaderName) {
    auto it = shaders.find(shaderName);
    if (it != shaders.end()) {
        ::BeginShaderMode(it->second);
    }
}

void ShaderManager::EndShaderMode() {
    ::EndShaderMode();
}

void ShaderManager::UnloadShader(const std::string& shaderName) {
    auto it = shaders.find(shaderName);
    if (it != shaders.end()) {
        ::UnloadShader(it->second);
        shaders.erase(it);
    }
}

void ShaderManager::UnloadAllShaders() {
    for (auto& pair : shaders) {
        ::UnloadShader(pair.second);
    }
    shaders.clear();
}

Shader ShaderManager::GetShader(const std::string& shaderName) {
    auto it = shaders.find(shaderName);
    if (it != shaders.end()) {
        return it->second;
    }
    // Return an empty Shader object if not found
    return Shader{ 0 };
}
