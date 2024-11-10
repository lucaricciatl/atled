#ifndef MODELFACTORY_HPP
#define MODELFACTORY_HPP

#include <memory>
#include "Model2DFactory.hpp"
#include "Model3DFactory.hpp"
#include "Model.hpp"

namespace graphics {

using ModelType = std::variant<Model2DType, Model3DType>;

class ModelFactory : public Model2DFactory, public Model3DFactory {
public:
    // General-purpose creation method using ModelType
    static std::shared_ptr<Model> CreateModel(const ModelType type) {
        switch (type) {
            // 2D Models
            case ModelType::circle:
                return Model2DFactory::CreateCircle();
            case ModelType::arc:
                return Model2DFactory::CreateArc();
            case ModelType::rectangle:
                return Model2DFactory::CreateRectangle();
            case ModelType::regularPolygon:
                return std::make_shared<RegularPolygon>();
            case ModelType::line:
                return Model2DFactory::CreateLine();
            case ModelType::polyline:
                return Model2DFactory::CreatePolyline();
            case ModelType::triangle:
                return Model2DFactory::CreateTriangle();
            case ModelType::polygon:
                return Model2DFactory::CreatePolygon();

            // 3D Models
            case ModelType::cube:
                return Model3DFactory::CreateCube();
            case ModelType::sphere:
                return Model3DFactory::CreateSphere();
            case ModelType::pyramid:
                return Model3DFactory::CreatePyramid();

            default:
                return nullptr;  // Return nullptr for unsupported types
        }
    }
};

}  // namespace graphics

#endif  // MODELFACTORY_HPP
