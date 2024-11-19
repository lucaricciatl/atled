#include "GraphicsComponent.hpp"

GraphicsComponent::GraphicsComponent(GameObject* owner, Mesh* mesh, Material* material)
    : Component(owner), mesh(mesh), material(material) {
    // Inizializzazione grafica
}

void GraphicsComponent::OnDraw() {
    // Logica di rendering
    if (mesh && material) {
        // Esegui il rendering del mesh con il materiale
    }
}
