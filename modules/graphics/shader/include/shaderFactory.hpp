#ifndef SHADERFACTORY_HPP
#define SHADERFACTORY_HPP

#include "IShader.hpp"
#include <memory>
#include <string>
#include "RaylibShader.hpp"

class ShaderFactory {
public:
    virtual ~ShaderFactory() = default;

    // Create a shader instance
    virtual std::unique_ptr<IShader> CreateShader() const = 0;
};

class RaylibShaderFactory : public ShaderFactory {
public:
    inline std::unique_ptr<IShader> CreateShader() const override {
    return std::make_unique<RaylibShader>();
};

};

#endif // SHADERFACTORY_HPP
