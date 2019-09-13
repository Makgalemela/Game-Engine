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
    _bulletSprite.scale(0.02f , 0.02f);
    
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

 void Bullet::BulletOutOfScreen(AliensDirection ad ){
     for(auto it = 0u ; it < _bullets.size(); ++it){
         if(ad == AliensDirection::DownFace&&_bullets.size() != 0 && _bullets.at(it).getPosition().y < 50.f){
             _bullets.erase(_bullets.begin() + it);
         }
     }
     
     for(auto it = 0u ; it < _bullets2.size(); ++it){
         if(ad == AliensDirection::UpFace && _bullets2.size() != 0 && _bullets2.at(it).getPosition().y > 570.f){
             _bullets2.erase(_bullets2.begin() + it);
         }
     }

 }
 

 void Bullet::BulletsCollusion(sf::RenderWindow& _window){
     for(auto it = 0u; it != _bullets.size(); ++it){
         for(auto i = 0u; i != _bullets2.size();++i ){
             
             if((_bullets2.size() != 0 && _bullets.size() != 0) && abs(_bullets2.at(i).getPosition().x - _bullets.at(it).getPosition().x)<10 &&
                abs(_bullets2.at(i).getPosition().y - _bullets.at(it).getPosition().y)<5){
              _bulletExplosionSprite.setPosition(_bullets2.at(i).getPosition().x-10,_bullets2.at(i).getPosition().y );
              _bullets.erase(_bullets.begin()+ it);
              _bullets2.erase(_bullets2.begin()+ i);
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

bool Bullet::alienShoot(sf::Sprite _alien){
    float _posX = _alien.getPosition().x;
    float _posY = _alien.getPosition().y;
    
    for(auto it = _bullets.begin(); it != _bullets.end(); ++it){
        if(abs((*it).getPosition().x - _posX) <10.f  && abs((*it).getPosition().y - _posY) <5.f){
            _bullets.erase(it--);
            return true;
        }
    }
    return false;
}

Bullet::~Bullet()
{
}

