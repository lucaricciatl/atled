

#include "Model2DFactory.hpp"
#include "Model3DFactory.hpp"
#include "ModelFactory.hpp"



namespace graphics {



    std::shared_ptr<Model> ModelFactory::CreateModel(ModelType modeltype) {
        switch (modeltype) {
            // 2D Models
        case ModelType::circle:
            return std::dynamic_pointer_cast<Model>(Model2DFactory::CreateCircle());
        case ModelType::arc:
            return std::dynamic_pointer_cast<Model>(Model2DFactory::CreateArc());
        case ModelType::rectangle:
            return std::dynamic_pointer_cast<Model>(Model2DFactory::CreateRectangle());
        case ModelType::line:
            return std::dynamic_pointer_cast<Model>(Model2DFactory::CreateLine());
        case ModelType::polyline:
            return std::dynamic_pointer_cast<Model>(Model2DFactory::CreatePolyline());
        case ModelType::triangle:
            return std::dynamic_pointer_cast<Model>(Model2DFactory::CreateTriangle());
        case ModelType::polygon:
            return std::dynamic_pointer_cast<Model>(Model2DFactory::CreatePolygon());

            // 3D Models
        case ModelType::cube:
            return std::dynamic_pointer_cast<Model>(Model3DFactory::CreateCube());
        case ModelType::sphere:
            return std::dynamic_pointer_cast<Model>(Model3DFactory::CreateSphere());
        case ModelType::pyramid:
            return std::dynamic_pointer_cast<Model>(Model3DFactory::CreatePyramid());

        default:
            return nullptr;
        }
    }


}  // namespace graphics
