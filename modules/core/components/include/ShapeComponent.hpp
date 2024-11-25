#pragma once

#include "Component.hpp"
#include "Entity.hpp"
#include "Model.hpp"
#include <ModelFactory.hpp>

using namespace graphics;

    class ShapeComponent : public Component {
    public:
        // Constructor
        explicit ShapeComponent(Entity* entity)
            : Component(entity), mModel(nullptr) {}

        // Destructor
        virtual ~ShapeComponent() {}

        // Update function
        void Update(double deltaTime) override {
            if (mModel) {

            }
        }

        // Mutator for the model with construction logic
        template <typename... Args>
        void SetModel(graphics::ModelType type, Args&&... args) {
            // Use the ModelFactory to create the model
            mModel = ModelFactory::CreateModel(type);

            // Perform additional logic if necessary
        }

    private:
        std::unique_ptr<graphics::Model> mModel; // The model instance managed as a polymorphic type
    };

