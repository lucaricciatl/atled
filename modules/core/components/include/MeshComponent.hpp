#include "Component.hpp"
#include "Entity.hpp"
#include "Model.hpp"
#include <ModelFactory.hpp>
#include <random>
#include <FrameComponent.hpp>

using namespace graphics;

    class MeshComponent : public Component {
    public:
        // Constructor
        explicit MeshComponent(Entity* entity, std::shared_ptr<ServiceProvider> serviceProvider)
            : Component(entity), mModel(nullptr) {
            graphicsManager = serviceProvider->GetGraphicManager();
            mFrame = entity->GetComponent<FrameComponent>()->GetFrame();
        }

        // Destructor
        virtual ~MeshComponent() {}

        // Update function
        void Update(double deltaTime) override {

        }

        // Mutator for the model with construction logic
        void Init() {
            auto mModel = ModelFactory::CreateModel<Mesh3D>();

            mModel->SetMesh();
            graphicsManager->AddShape(1, mModel);

        }

    private:
        std::shared_ptr<graphics::Model> mModel; // The model instance managed as a polymorphic type
        std::shared_ptr<graphics::IGraphicManager> graphicsManager;
        std::shared_ptr<physics::Frame> mFrame;
    };

