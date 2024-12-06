#pragma once

#include "Component.hpp"
#include "Entity.hpp"
#include "Model.hpp"
#include "ModelFactory.hpp"
#include "FrameComponent.hpp"
#include <memory>
#include <IGraphicManager.hpp>

using namespace graphics;

class WorldComponent : public Component {
public:
    // Constructor
    explicit WorldComponent(Entity* entity, std::shared_ptr<ServiceProvider> serviceProvider)
        : Component(entity), mModel(nullptr) {
        graphicsManager = serviceProvider->GetGraphicManager();
        mFrame = entity->GetComponent<FrameComponent>()->GetFrame();
    }

    // Destructor
    virtual ~WorldComponent() {
        // Remove the model from the graphics manager if it exists
        if (mModel) {
            //graphicsManager->RemoveShape(mModel);
            mModel.reset();
        }
    }

    // Accessor for the model
    template <typename ModelClass>
    std::shared_ptr<ModelClass> GetModel() {
        return std::dynamic_pointer_cast<ModelClass>(mModel);
    }

    void Init() {
    // Add axes
    Color red = { 255, 0, 0, 255 };    // X-axis color
    Color green = { 0, 255, 0, 255 };  // Y-axis color
    Color blue = { 0, 0, 255, 255 };   // Z-axis color

    // X-axis line
    auto xAxis = Model3DFactory::CreateLine3D();
    xAxis->SetStartPos({ -1.0f, 0.0f, 0.0f });
    xAxis->SetEndPos({ 1.0f, 0.0f, 0.0f });
    xAxis->SetColor(red);
    graphicsManager->AddShape(1, xAxis);

    // Y-axis line
    auto yAxis = Model3DFactory::CreateLine3D();
    yAxis->SetStartPos({ 0.0f, -1.0f, 0.0f });
    yAxis->SetEndPos({ 0.0f, 1.0f, 0.0f });
    yAxis->SetColor(green);
    graphicsManager->AddShape(1, yAxis);

    // Z-axis line
    auto zAxis = Model3DFactory::CreateLine3D();
    zAxis->SetStartPos({ 0.0f, 0.0f, -1.0f });
    zAxis->SetEndPos({ 0.0f, 0.0f, 1.0f });
    zAxis->SetColor(blue);
    graphicsManager->AddShape(1, zAxis);
    }

private:
    std::shared_ptr<graphics::Model> mModel;
    std::shared_ptr<graphics::IGraphicManager> graphicsManager;
    std::shared_ptr<physics::Frame> mFrame;
};
