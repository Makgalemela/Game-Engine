#ifndef ALIENS_HPP
#define ALIENS_HPP
#include <vector>
#include <tuple>
#include <SFML/Graphics.hpp>


//*******************************************************
//
//class Aliens load and cread enemy aliens
//
//
//*********************************************************
using namespace std;
class Aliens
{
public:
    Aliens();
    ~Aliens();
    
    
//    *******************************************************
//    
//    the method load alien sprites from the resource 
//    
//    \param return void
//    
//    *****************************************************
    void loadAliens();
    
    
//    **************************************************************************
//    
//    the method returns a vertor of aliens and the position at which the aliens will be drawn
//    on the Screen
//    
//    \param return tuple<vector, vector>
//    
//    **************************************************************************
    tuple<vector<sf::Sprite> , sf::Vector2f> aliensSprite() const;
    
    
//    **************************************************************************
//    
//    the method returns a vertor of aliens 
//    
//    
//    \param return vector
//    
//    **************************************************************************
    
    std::vector<sf::Sprite> aliensSpriteAlone() const;
private:
    sf::Texture _alienTexture;
    sf::Texture _alienTexture2;
    sf::Texture _alienTexture3;
    sf::Sprite _alienSprite;
    sf::Sprite _alienSprite2;
    sf::Sprite _alienSprite3;
    vector<sf::Sprite> aliens;
    sf::Vector2f _position;
};

#endif // ALIENS_HPP
