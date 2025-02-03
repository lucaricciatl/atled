#ifndef RAYLIBSHADER_HPP
#define RAYLIBSHADER_HPP

#include "IShader.hpp"
#include "raylib.hpp"
#include "vector"
class RaylibShader : public IShader {
   public:
    RaylibShader();
    ~RaylibShader();

    bool LoadFromFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) override;
    raylib::Shader GetShader(){return shader;}

    raylib::Shader shader;
    std::string shaderSearchPaths;
    bool isLoaded;
};

#endif // RAYLIBSHADER_HPP
