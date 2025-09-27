#include "shaderFactory.hpp"
#include "raylibShader.hpp"

std::unique_ptr<IShader> RaylibShaderFactory::CreateShader() const { return std::make_unique<RaylibShader>(); };

std::unique_ptr<IShader> RaylibShaderFactory::CreateShader(std::string aShaderName) const {
    auto shader = std::make_unique<RaylibShader>();

    for (auto path : mSearchPaths) {
        auto vertexShaderName = path + aShaderName + ".vs";
        auto fragmentShaderName = path + aShaderName + ".fs";
        auto success = shader->LoadFromFiles(vertexShaderName, fragmentShaderName);
        if (success) {
            return shader;
        }
    }
    return shader;
};