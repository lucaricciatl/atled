#include "ScriptComponent.hpp"

ScriptComponent::ScriptComponent(GameObject* owner, Script* script)
    : Component(owner), script(script) {
    // Inizializzazione dello script
}

void ScriptComponent::OnStart() {
    script->ExecuteFunction("OnStart", owner);
}

void ScriptComponent::OnUpdate(float deltaTime) {
    script->ExecuteFunction("OnUpdate", owner, deltaTime);
}

void ScriptComponent::OnDraw() {
    script->ExecuteFunction("OnDraw", owner);
}
