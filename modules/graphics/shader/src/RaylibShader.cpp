#include "RaylibShader.hpp"

RaylibShader::RaylibShader() : isLoaded(false) {
    shader = { 0 };
}

RaylibShader::~RaylibShader() {
    Unload();
}

bool RaylibShader::LoadFromFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    shader = raylib::LoadShader(vertexShaderPath.c_str(), fragmentShaderPath.c_str());
    isLoaded = raylib::IsShaderReady(shader);
    return isLoaded;
}

bool RaylibShader::LoadFromMemory(const std::string& vertexShaderCode, const std::string& fragmentShaderCode) {
    shader = raylib::LoadShaderFromMemory(vertexShaderCode.c_str(), fragmentShaderCode.c_str());
    isLoaded = raylib::IsShaderReady(shader);
    return isLoaded;
}

bool RaylibShader::IsReady() const {
    return isLoaded;
}

int RaylibShader::GetUniformLocation(const std::string& uniformName) const {
    return GetShaderLocation(shader, uniformName.c_str());
}

void RaylibShader::SetUniformValue(int location, const void* value, int uniformType) {
    SetShaderValue(shader, location, value, uniformType);
}

void RaylibShader::Unload() {
    if (isLoaded) {
        UnloadShader(shader);
        isLoaded = false;
    }
}
