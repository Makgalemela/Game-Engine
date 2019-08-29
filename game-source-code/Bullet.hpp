#ifndef BULLET_HPP
#define BULLET_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "Aliens.hpp"

class Bullet
{
public:

    Bullet();
    ~Bullet();
    
    void fireBullet(sf::RenderWindow &_window , sf::Vector2f _bulletPosition);
    void startFiring();
    void collusion();
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
