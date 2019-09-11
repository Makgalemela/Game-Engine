#ifndef ALIENS_HPP
#define ALIENS_HPP
#include <vector>
#include <tuple>
#include <SFML/Graphics.hpp>
#include "StopWatch.h"


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
    tuple<vector<sf::Sprite> ,vector<sf::Sprite>,sf::Vector2f ,sf::Vector2f> aliensSprite() const;
    
    
//    **************************************************************************
//    
//    the method returns a vertor of aliens 
//    
//    
//    \param return vector
//    
//    **************************************************************************
    
    std::vector<sf::Sprite> aliensSpriteAlone() const;
    
    
    void AlienMovement();
private:
    ///buttom aliens
    sf::Texture _alienTexture;
    sf::Texture _alienTexture2;
    sf::Texture _alienTexture3;
    sf::Sprite _alienSprite;
    sf::Sprite _alienSprite2;
    sf::Sprite _alienSprite3;
    vector<sf::Sprite> aliens;
    sf::Vector2f _position;
    ///upper aliens
    
    sf::Texture _alienTextureu;
    sf::Texture _alienTexture2u;
    sf::Texture _alienTexture3u;
    sf::Sprite _alienSpriteu;
    sf::Sprite _alienSprite2u;
    sf::Sprite _alienSprite3u;
    vector<sf::Sprite> aliensu;
    sf::Vector2f _positionu;
    
    bool _changeAlienDirection;
    StopWatch _watch;
};

#endif // ALIENS_HPP
