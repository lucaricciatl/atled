#ifndef GRAPHICSCOMPONENT_HPP
#define GRAPHICSCOMPONENT_HPP

#include "Component.hpp"
#include "Mesh.hpp"      // Supponendo che tu abbia una classe Mesh
#include "Material.hpp"  // Supponendo che tu abbia una classe Material

class GraphicsComponent : public Component {
public:
    Mesh* mesh;
    Material* material;

    GraphicsComponent(GameObject* owner, Mesh* mesh, Material* material);

    void OnDraw() override;
};

#endif // GRAPHICSCOMPONENT_HPP
