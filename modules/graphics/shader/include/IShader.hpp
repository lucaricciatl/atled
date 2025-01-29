#ifndef ISHADER_HPP
#define ISHADER_HPP

#include <string>

class IShader {
public:
    virtual ~IShader() = default;

    // Load shader from vertex and fragment shader files
    virtual bool LoadFromFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) = 0;
};

#endif // ISHADER_HPP
