#ifndef SHADERFACTORY_HPP
#define SHADERFACTORY_HPP

#include "IShader.hpp"
#include <memory>
#include <string>

class ShaderFactory {
public:
    virtual ~ShaderFactory() = default;

    // Create a shader instance
    virtual std::unique_ptr<IShader> CreateShader() const = 0;
};

class RaylibShaderFactory : public ShaderFactory {
public:
    std::unique_ptr<IShader> CreateShader() const override;
};

#endif // SHADERFACTORY_HPP
