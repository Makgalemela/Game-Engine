#ifndef ALIENS_HPP
#define ALIENS_HPP
#include <vector>
#include <tuple>
#include <SFML/Graphics.hpp>
#include "StopWatch.h"
#include "Score.hpp"
#include <cstdlib>
#include <ctime>
//*******************************************************
//
//class Aliens load and cread enemy aliens
//
//
//*********************************************************

enum class AliensDirection{
    UpFace =0,
    DownFace
    
};
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
    tuple<vector<sf::Sprite> ,vector<sf::Sprite>> aliensSprite() const;
    
    
//    **************************************************************************
//    
//    the method returns a vertor of aliens 
//    
//    
//    \param return vector
//    
//    **************************************************************************
    
    std::vector<sf::Sprite> aliensSpriteAlone() const;
    
    
    void alienIsMoving(sf::RenderWindow &_windows);
    void setAlienPosition();
    void alienIsShot(const int& it, const AliensDirection& ad = AliensDirection::DownFace);
    bool IsAlienAlive(const int& it, const AliensDirection& dir) const;
    bool aliensAtBottonOrTop() const;
    bool allAliensKilled() const;
    
    
    void scale();
private:
    ///buttom aliens
    sf::Texture alienTexture[6];
    sf::Sprite alienSprite[6];
    vector<sf::Sprite> aliens[2];
    sf::Vector2f _position[2];
    bool _changeAlienDirection[2];
    StopWatch _watch;
    Score _score;
    
    std::vector<bool> alienIsAlive[2];
    std::vector<AliensDirection> alienOrientation[2];
    
    void setTexture();
    
    void update(const float& _pixel, const int& i);
    void updateRows(const int& i);
    sf::Vector2f alienFire();
};

#endif // ALIENS_HPP
