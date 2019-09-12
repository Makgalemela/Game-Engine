#include "Bullet.hpp"
#include <iostream>
Bullet::Bullet()
{
    _bulletSpeed = -0.09f;
    _fire = false;
    if(!_bulletTexture.loadFromFile("../executables/resources/bullet.png") ||
        !_bulletExplosionTexture.loadFromFile("../executables/resources/explosion_bullet.png") ){
        std::cerr<<"Failed to load bullet sprite"<<std::endl;
    }
    _bulletSprite.setTexture(_bulletTexture);
    _bulletSprite.scale(0.04f , 0.02f);
    
    _bulletExplosionSprite.setTexture(_bulletExplosionTexture);
    _bulletExplosionSprite.scale(0.1f , 0.1f);
}


///The function triggers fire
void Bullet::startFiring(FiringDirection fd){
    if(fd == FiringDirection::down)
         _fire = true;
    else  if(fd == FiringDirection::up)
        _fire2 = true;
}

 bool Bullet::collusion(const float& positionx ,const float& positiony ){
    
     for(auto it = 0u ; it < _bullets.size(); ++it){
         if(_bullets.at(it).getPosition().y < 50.f){
             _bullets.erase(_bullets.begin() + it);
         }
         if(_bullets.size() != 0 && abs(positionx - _bullets.at(it).getPosition().x) <10 &&
                abs(positiony - _bullets.at(it).getPosition().y) <10){
              _bullets.erase(_bullets.begin() + it);
             return true;
         }
     }
     return false;
 }
 
 
  bool Bullet::collusion2(const float& positionx ,const float& positiony ){
    
     for(auto it = 0u ; it < _bullets2.size(); ++it){
         if(_bullets2.at(it).getPosition().y > 560.f){
             _bullets2.erase(_bullets2.begin() + it);
         }
         if(_bullets2.size() != 0 && abs(positionx - _bullets2.at(it).getPosition().x) <10 &&
                abs(positiony - _bullets2.at(it).getPosition().y) <10){
              _bullets2.erase(_bullets2.begin() + it);
             return true;
         }
     }
     return false;
 }
 
 
 void Bullet::BulletsCollusion(sf::RenderWindow& _window){
     for(auto it = 0u; it != _bullets.size(); ++it){
         for(auto i = 0u; i != _bullets2.size();++i ){
             
             if((_bullets2.size() != 0 && _bullets.size() != 0) && abs(_bullets2.at(i).getPosition().x - _bullets.at(it).getPosition().x)<10 &&
                abs(_bullets2.at(i).getPosition().y - _bullets.at(it).getPosition().y)<5){
             
              sf::Vector2f _pos;
              _bulletExplosionSprite.setPosition(_bullets2.at(i).getPosition().x-10,_bullets2.at(i).getPosition().y );
              for(auto t = 0u; t != 100 ;++t ){
                  _window.draw(_bulletExplosionSprite);
              }
              return;
         }
         }
     }
     return;
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
            _bullets.at(it).move(0, -0.09f);
    }
}

void Bullet::fireBullet2(sf::RenderWindow &_window , sf::Vector2f _bulletPosition)
{   
    if(_fire2){
         _bulletPosition.x += 18.f;
        _bulletPosition.y += 25.f;        
        _bulletSprite.setPosition(_bulletPosition);
        _bullets2.push_back(_bulletSprite);
        _fire2 = false;
    }
    for(auto it =  0u; it != _bullets2.size() ; ++it){
             _window.draw(_bullets2.at(it));
            _bullets2.at(it).move(0, +0.09f);
    }
}
Bullet::~Bullet()
{
}

