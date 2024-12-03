#pragma once

#include "Component.hpp"
#include "Entity.hpp"
#include "Model.hpp"
#include "ModelFactory.hpp"
#include "FrameComponent.hpp"
#include <memory>

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
    virtual ~ShapeComponent() {
        // Remove the model from the graphics manager if it exists
        if (mModel) {
            //graphicsManager->RemoveShape(mModel);
            mModel.reset();
        }
    }

    // Update function
    void Update(double deltaTime) override {
        // Update logic if needed
    }

    // Mutator for the model with construction logic
    template <typename ModelClass, typename... Args>
    void SetModel(Args&&... args) {
        // Remove the existing model from the graphics manager if it exists
        if (mModel) {
            //graphicsManager->RemoveShape(mModel);
            mModel.reset();
        }

        // Use the ModelFactory to create the model with the given arguments
        mModel = ModelFactory::CreateModel<ModelClass>(std::forward<Args>(args)...);
        if (mModel) {
            mModel->SetFrame(mFrame);
            graphicsManager->AddShape(1, mModel);
        }
        else {
            // Handle the error if model creation failed
            // You might want to log an error or throw an exception
        }
    }

    // Accessor for the model
    template <typename ModelClass>
    std::shared_ptr<ModelClass> GetModel() {
        return std::dynamic_pointer_cast<ModelClass>(mModel);
    }

    void Init() {
        // Initialization logic if needed
    }

private:
    std::shared_ptr<graphics::Model> mModel;
    std::shared_ptr<graphics::IGraphicManager> graphicsManager;
    std::shared_ptr<physics::Frame> mFrame;
};
