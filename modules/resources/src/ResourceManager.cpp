#include "ResourceManager.hpp"
#include "Resouce.hpp"
#include <stdexcept>
#include "nlohmann/json.hpp"

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