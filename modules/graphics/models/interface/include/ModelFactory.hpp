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
        pyramid,
    };
class ModelFactory : public Model2DFactory, public Model3DFactory {
public:
	static std::shared_ptr<Model> CreateModel(ModelType modeltype);
};

}  // namespace graphics

#endif  // MODEL_FACTORY_HPP

