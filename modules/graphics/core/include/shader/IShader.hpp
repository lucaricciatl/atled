#ifndef ISHADER_HPP
#define ISHADER_HPP

#include <string>

class IShader {
public:
    virtual ~IShader() = default;

    // Load shader from vertex and fragment shader files
    virtual bool LoadFromFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) = 0;

    // Load shader from vertex and fragment shader code strings
    virtual bool LoadFromMemory(const std::string& vertexShaderCode, const std::string& fragmentShaderCode) = 0;

    // Check if the shader is ready
    virtual bool IsReady() const = 0;

    // Get the location of a uniform variable in the shader
    virtual int GetUniformLocation(const std::string& uniformName) const = 0;

    // Set a uniform value in the shader
    virtual void SetUniformValue(int location, const void* value, int uniformType) = 0;

    // Unload the shader
    virtual void Unload() = 0;
};

#endif // ISHADER_HPP
