// Base class for materials
class Material {
public:
    Material() = default;
    virtual ~Material() = default;
    
    // Pure virtual function that derived classes must implement.
    virtual std::string getInfo() const = 0;
};