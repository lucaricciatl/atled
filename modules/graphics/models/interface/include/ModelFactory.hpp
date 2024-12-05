#ifndef MODEL_FACTORY_HPP
#define MODEL_FACTORY_HPP

#include "Model2DFactory.hpp"
#include "Model3DFactory.hpp"
#include "Model.hpp"
#include <variant>
#include <memory>

namespace graphics {

    enum class ModelType {
        // 2D Models
        circle,
        arc,
        rectangle,
        regularPolygon,
        line,
        polyline,
        triangle,
        polygon,

        // 3D Models
        cube,
        sphere,
        Mesh3D,
    };

class ModelFactory : public Model2DFactory, public Model3DFactory {
public:
    template <typename ModelClass, typename... Args>
    static std::shared_ptr<ModelClass> CreateModel(Args&&... args) {
        if constexpr (std::is_same_v<ModelClass, Circle>)
            return Model2DFactory::CreateCircle(std::forward<Args>(args)...);
        else if constexpr (std::is_same_v<ModelClass, Arc>)
            return Model2DFactory::CreateArc(std::forward<Args>(args)...);
        else if constexpr (std::is_same_v<ModelClass, Rectangle>)
            return Model2DFactory::CreateRectangle(std::forward<Args>(args)...);
        else if constexpr (std::is_same_v<ModelClass, Line>)
            return Model2DFactory::CreateLine(std::forward<Args>(args)...);
        else if constexpr (std::is_same_v<ModelClass, Polyline>)
            return Model2DFactory::CreatePolyline(std::forward<Args>(args)...);
        else if constexpr (std::is_same_v<ModelClass, Triangle>)
            return Model2DFactory::CreateTriangle(std::forward<Args>(args)...);
        else if constexpr (std::is_same_v<ModelClass, Polygon>)
            return Model2DFactory::CreatePolygon(std::forward<Args>(args)...);
        else if constexpr (std::is_same_v<ModelClass, Cube>)
            return Model3DFactory::CreateCube(std::forward<Args>(args)...);
        else if constexpr (std::is_same_v<ModelClass, Sphere>)
            return Model3DFactory::CreateSphere(std::forward<Args>(args)...);
        else if constexpr (std::is_same_v<ModelClass, Cylinder>)
            return Model3DFactory::CreateCylinder(std::forward<Args>(args)...);
        else if constexpr (std::is_same_v<ModelClass, Plane>)
            return Model3DFactory::CreatePlane(std::forward<Args>(args)...);
        else
            static_assert(std::is_base_of_v<Model, ModelClass>, "Invalid ModelClass type provided.");
    }
};

}  // namespace graphics

#endif  // MODEL_FACTORY_HPP

