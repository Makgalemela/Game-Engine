#include "ResourceManager.hpp"

ResourceManager::ResourceManager()
{
}


void ResourceManager::loadResources(ResourceID _id , const std::string& _filename){
    sf::Texture _texture;
    if(!_texture.loadFromFile(_filename))
        throw std::runtime_error("Failed to load the resource at "+_filename);
    resourseHolder.insert(std::make_pair(_id ,_texture));
}


 sf::Texture ResourceManager::get(ResourceID _id) const{    
    return resourseHolder.find(_id)->second;
}
ResourceManager::~ResourceManager()
{
}

