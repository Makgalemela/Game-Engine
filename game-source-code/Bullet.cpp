#include "Bullet.hpp"
#include <iostream>



Bullet::Bullet()
{
    _bulletSpeed = -0.1f;
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

 void Bullet::collusion(vector<sf::Sprite> aliens){
    
     for(auto it = 0u ; it < _bullets.size(); ++it){
         if(_bullets.at(it).getPosition().y < 20.f){
             _bullets.erase(_bullets.begin() + it);
         }
         for(auto i = 0u ; i < aliens.size(); ++i){
             if( _bullets.size() != 0 && aliens.at(i).getPosition().y == _bullets.at(it).getPosition().y &&
             aliens.at(i).getPosition().x == _bullets.at(it).getPosition().x ){
             ///_bullets.erase(_bullets.begin() + it);
             ///aliens.erase(aliens.begin() + i);
             ///std::cout<<aliens.at(i).getPosition().y << " "<< _bullets.at(it).getPosition().y<<std::endl;
             std::cout<<"Collussion detected"<<std::endl;
            }
         }
         
     }
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

