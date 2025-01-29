#include "RaylibShader.hpp"
    #define GLSL_VERSION            330

RaylibShader::RaylibShader() : isLoaded(false) {
    shader = { 0 };
}

RaylibShader::~RaylibShader() {
}

bool RaylibShader::LoadFromFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    shader = raylib::LoadShader(raylib::TextFormat(vertexShaderPath.c_str(),GLSL_VERSION ), raylib::TextFormat(fragmentShaderPath.c_str(),GLSL_VERSION));
    isLoaded = raylib::IsShaderReady(shader);
    return isLoaded;
}

