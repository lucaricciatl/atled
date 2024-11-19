// IEngine.hpp
#pragma once

#include <functional>
#include <vector> 

namespace engine {

class IEngine {
public:
    virtual ~IEngine() = default;

    // Virtual functions that derived classes can override
    virtual void Init() = 0;
    virtual void Start() = 0;
    virtual void Shutdown() = 0;
    virtual void Stop()= 0 ;

};
}