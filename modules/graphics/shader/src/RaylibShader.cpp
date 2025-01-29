#include "RaylibShader.hpp"

RaylibShader::RaylibShader() : isLoaded(false) {
    shader = { 0 };
}

RaylibShader::~RaylibShader() {
}

bool RaylibShader::LoadFromFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    shader = raylib::LoadShader(vertexShaderPath.c_str(), fragmentShaderPath.c_str());
    isLoaded = raylib::IsShaderReady(shader);
    return isLoaded;
}

