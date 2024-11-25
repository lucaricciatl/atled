#ifndef RAYLIBSHADER_HPP
#define RAYLIBSHADER_HPP

#include "IShader.hpp"
#include "raylib.hpp"

class RaylibShader : public IShader {
public:
    RaylibShader();
    ~RaylibShader() override;

    bool LoadFromFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) override;
    bool LoadFromMemory(const std::string& vertexShaderCode, const std::string& fragmentShaderCode) override;
    bool IsReady() const override;
    int GetUniformLocation(const std::string& uniformName) const override;
    void SetUniformValue(int location, const void* value, int uniformType) override;
    void Unload() override;

private:
    raylib::Shader shader;
    bool isLoaded;
};

#endif // RAYLIBSHADER_HPP
