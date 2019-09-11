#ifndef BULLET_HPP
#define BULLET_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "Aliens.hpp"
#include <cmath>
///*****************************************************************
//    /description - this class exclusivelly load and create Bullet
//    the class create utility method for bullet functionalities as
//    methods which allow bullet to accessed,
//    furthermore the class as also create different bullets for different weapons
//*****************************************************************/
class Bullet
{
public:

    Bullet();
    ~Bullet();
//    ******************************************************************
//        the method fires a bullet and draws it's movement of the the screen
//    ********************************************************************
    
    void fireBullet(sf::RenderWindow &_window , sf::Vector2f _bulletPosition);
    
//    **********************************************************************
//    the method is called when keyboard key F is pressed
//    it set bool _fire to true signalling that the bullet can be fired
//    **********************************************************************
    
    void startFiring();
    
    
//     ******************************************************************************
//     the method detect the bullet colusion with other object - e.g aliens , cannon.
//     futher more also detect when the bullet is going off the screen
//     and erase it
//     *******************************************************************************
//     
    bool collusion(const float& positionx, const float& positiony);
private:
     Aliens _aliens;
     float _bulletSpeed;
     float _bulletTimer;
     float _ellaspsedTime;
     bool _fire;
     
     sf::Vector2f _bulletPosition;
     sf::Sprite _bulletSprite;
     sf::Texture _bulletTexture;
     std::vector<sf::Sprite> _bullets;

};

#endif // BULLET_HPP
