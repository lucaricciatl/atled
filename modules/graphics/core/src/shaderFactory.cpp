#include "ShaderFactory.hpp"
#include "RaylibShader.hpp"

std::unique_ptr<IShader> RaylibShaderFactory::CreateShader() const {
    return std::make_unique<RaylibShader>();
}
