#include "ResourcesSystem.hpp"
#include <iostream>  // For debug/logging purposes

ResourceSystem::ResourceSystem(ResourceManager* resourceMgr)
    : resourceManager(std::shared_ptr<ResourceManager>(resourceMgr)) {}

void ResourceSystem::Init() {
    // Initialize system (e.g., load default search paths if required)
}

void ResourceSystem::Update(float deltaTime) {
    // Update logic, if any, for the resource system
}

void ResourceSystem::Shutdown() {
    // Cleanup resources and shutdown
}

void ResourceSystem::LoadTextures(){
    static auto TexturesResFolder = "./Textures";
    auto path = ResPath + TexturesResFolder;
};

void ResourceSystem::LoadSound(){
    static auto SoundResFolder = "./Sound";
    auto path = ResPath + SoundResFolder;
};

void ResourceSystem::LoadShaders(){
    static auto ShadersFolder = "./Shaders";
    auto path = ResPath + ShadersFolder;
};

void ResourceSystem::LoadAssets(){
    static auto AssetsResFolder = "./Assets";
    auto path = ResPath + AssetsResFolder;
};

void ResourceSystem::LoadResources(){
    LoadTextures();
    LoadShaders();
    LoadSound();
    LoadAssets();
}