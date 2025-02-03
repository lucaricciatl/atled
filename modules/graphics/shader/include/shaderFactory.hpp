#ifndef SHADERFACTORY_HPP
#define SHADERFACTORY_HPP

#include <filesystem>
#include <memory>
#include <string>

#include "IShader.hpp"
#include "RaylibShader.hpp"

class ShaderFactory {
public:
    virtual ~ShaderFactory() = default;

    // Create a shader instance
    virtual std::unique_ptr<IShader> CreateShader() const = 0;
    virtual std::unique_ptr<IShader> CreateShader(std::string aShaderName) const = 0;

    virtual void AddSearchPath() const = 0;
    virtual void GetShadersFilesList() const = 0;
    virtual std::string GetShaderFilePath() const = 0;
};

class RaylibShaderFactory : public ShaderFactory {
public:
 std::unique_ptr<IShader> CreateShader() const override;
 std::unique_ptr<IShader> CreateShader(std::string aShaderName) const override;
 // void AddSearchPath() const override;
 // void GetShadersFilesList() const override;
 // std::string GetShaderFilePath() const override;
 std::vector<std::string> mSearchPaths;
};

#endif // SHADERFACTORY_HPP
