#include "ResourceManager.hpp"
#include "Resouce.hpp"
#include <stdexcept>

using namespace resources;

ResourceManager::ResourceManager() = default;

ResourceManager::~ResourceManager() {
    UnloadAll();
}

    void ResourceManager::Load(std::string aPath){
        
}

    void ResourceManager::Unload() {
}

    bool ResourceManager::IsLoaded(){
        return false;
}


    void ResourceManager::UnloadAll() {
}