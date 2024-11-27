#pragma once

#include "Component.hpp"
#include "Entity.hpp"
#include "Model.hpp"
#include <ModelFactory.hpp>
#include <random>

using namespace graphics;

    class ShapeComponent : public Component {
    public:
        // Constructor
        explicit ShapeComponent(Entity* entity, std::shared_ptr<ServiceProvider> serviceProvider)
            : Component(entity), mModel(nullptr) {
            graphicsManager = serviceProvider->GetGraphicManager();
            mFrame = entity->GetComponent<FrameComponent>()->GetFrame();
        }

        // Destructor
        virtual ~ShapeComponent() {}

        // Update function
        void Update(double deltaTime) override {

        }

        // Mutator for the model with construction logic
        template <typename ModelClass, typename ... Args>
        void SetModel(Args&&... args) {
            // Use the ModelFactory to create the model
            mModel = ModelFactory::CreateModel<ModelClass>();
            mModel->SetFrame(mFrame);
            graphicsManager->AddShape(1,mModel);

        }

    private:
        std::shared_ptr<graphics::Model> mModel; // The model instance managed as a polymorphic type
        std::shared_ptr<graphics::IGraphicManager> graphicsManager;
        std::shared_ptr<physics::Frame> mFrame;
    };

