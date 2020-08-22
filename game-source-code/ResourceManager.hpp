#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
/**
 * @class ResourceManager
 * @author 879024
 * @date 22/09/2019
 * @file ResourceManager.hpp
 * @brief 
 */


enum class ResourceID{
    
    UpperCannon =0,
    LowerCannon,
    Splash,
    DownFacingAlienFirst,
    DownFacingAlienSecond,
    DownFacingAlienThird,
    UpFacingAlienFirst,
    UpFacingAlienSecond,
    UpFacingAlienThird,
    Bullets,
    Default
};

class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();
    
    void loadResources(ResourceID , const std::string &_filename);
    sf::Texture get(ResourceID _id) const;
;private:
  
    std::map<ResourceID , sf::Texture> resourseHolder;
};

#endif // RESOURCEMANAGER_HPP
