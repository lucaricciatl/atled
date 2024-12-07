#ifndef PHISICCOMPONENT_HPP
#define PHISICCOMPONENT_HPP

#include "Component.hpp"
#include <Action.hpp>
#include "ICollider.hpp"
#include "ColliderFactory.hpp"

class RigidBodyComponent : public Component {
public:
    RigidBodyComponent(Entity* owner, std::shared_ptr<ServiceProvider>) : Component(owner){
    };

    void OnAction(Action action, bool activated);
    void Update(float deltaTime);

    void SetStatic(bool aIsStatic){mIsStatic = aIsStatic;};
    bool IsStatic(){return mIsStatic;};
    void ApplyGravity(bool aGravityFlag){mGravityFlag = aGravityFlag;};
    void EnableCollision(bool aIsCollidable){mIsCollidable = aIsCollidable;};

private:

    std::shared_ptr<ICollider> mCollider;

    bool mIsStatic;
    bool mIsCollidable;
    bool mGravityFlag;
};

#endif // PLAYERCONTROLLER_HPP