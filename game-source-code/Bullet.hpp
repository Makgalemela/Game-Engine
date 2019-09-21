#ifndef BULLET_HPP
#define BULLET_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "Aliens.hpp"
#include <cmath>
#include <tuple>
#include "StopWatch.h"
#include <cstdlib>
///*****************************************************************
//    /description - this class exclusivelly load and create Bullet
//    the class create utility method for bullet functionalities as
//    methods which allow bullet to accessed,
//    furthermore the class as also create different bullets for different weapons
//*****************************************************************/

enum class FiringDirection{
    up = 0,
    down,
    defaultd
};

class Aliens;
class Bullet
{
public:

    Bullet();
    ~Bullet();
//    ******************************************************************
//        the method fires a bullet and draws it's movement of the the screen
//    ********************************************************************
    
    void fireBullet(sf::RenderWindow &_window );
  
    
//    **********************************************************************
//    the method is called when keyboard key F is pressed
//    it set bool _fire to true signalling that the bullet can be fired
//    **********************************************************************
    
   void startFiring(const FiringDirection& fd,sf::Vector2f _bulletPosition);
    
    
//     ******************************************************************************
//     the method detect the bullet colusion with other object - e.g aliens , cannon.
//     futher more also detect when the bullet is going off the screen
//     and erase it
//     *******************************************************************************
//     
    bool collusion2(const float& positionx, const float& positiony);
    bool collusion(sf::Vector2f _Pos , AliensDirection ad);
    void BulletsCollusion(sf::RenderWindow& _window);
    
    void BulletOutOfScreen();
    bool alienShoot(sf::Sprite _alien, AliensDirection dir);
    std::tuple<std::vector<sf::Sprite>*, std::vector<FiringDirection>*> getBullets() ;
    void aliensFiring();
    
    
    
private:
     Aliens _aliens;
     StopWatch _stopwatch;
     float _bulletSpeed;
     float _bulletTimer;
     float _ellaspsedTime;
     std::vector<FiringDirection> bulletOrientation;
    
     
     
     sf::Vector2f _bulletPosition;
     sf::Sprite _bulletSprite;
     sf::Texture _bulletTexture;
     sf::Sprite _bulletExplosionSprite;
     sf::Texture _bulletExplosionTexture;
     std::vector<sf::Sprite> _bullets;
//     std::vector<sf::Sprite> _bullets2;

};

#endif // BULLET_HPP
