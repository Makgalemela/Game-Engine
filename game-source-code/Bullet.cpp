#include "Bullet.hpp"
#include <iostream>
Bullet::Bullet()
{
    _bulletSpeed = -10.f;
    _fire = false;
    if(!_bulletTexture.loadFromFile("../executables/resources/bullet.png")){
        std::cerr<<"Failed to load bullet sprite"<<std::endl;
    }
    _bulletSprite.setTexture(_bulletTexture);
    _bulletSprite.scale(0.04f , 0.02f);
}

void Bullet::startFiring(){
    _fire = true;
}

 bool Bullet::collusion(const float& positionx ,const float& positiony ){
    

     for(auto it = 0u ; it < _bullets.size(); ++it){
         if(_bullets.at(it).getPosition().y < 20.f){
             _bullets.erase(_bullets.begin() + it);
         }
         if(_bullets.size() != 0 && abs(positionx - _bullets.at(it).getPosition().x) <10 && abs(positiony - _bullets.at(it).getPosition().y) <10){
              _bullets.erase(_bullets.begin() + it);
             return true;
         }
    
     }
     return false;
 }
void Bullet::fireBullet(sf::RenderWindow &_window , sf::Vector2f _bulletPosition)
{   
    if(_fire){
        _bulletPosition.x += 18.f;
        _bulletPosition.y -= 25.f;
        _bulletSprite.setPosition(_bulletPosition);
        _bullets.push_back(_bulletSprite);
        _fire = false;
    }
    for(auto it =  0u; it != _bullets.size() ; ++it){
             _window.draw(_bullets.at(it));
            _bullets.at(it).move(0, _bulletSpeed);
    }
}
Bullet::~Bullet()
{
}

