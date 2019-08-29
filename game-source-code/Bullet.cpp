#include "Bullet.hpp"
#include <iostream>


Bullet::Bullet()
{
    _bulletSpeed = -0.5f;
    if(!_bulletTexture.loadFromFile("../executables/resources/bullet.png")){
        std::cerr<<"Failed to load bullet sprite"<<std::endl;
    }
    _bulletSprite.setTexture(_bulletTexture);
    _bulletSprite.scale(0.01f , 0.01f);
}

void Bullet::startFiring(){
    _fire = true;
}

 void Bullet::collusion(){
     ///std::cout<<aliens.size()<<std::endl;
     for(auto it = 0u ; it < _bullets.size(); ++it){
         if(_bullets.at(it).getPosition().y < 20.f){
             _bullets.erase(_bullets.begin() + it);
         }
//         for(auto i = 0u ; i < aliens.size(); ++i){
//             if(aliens.at(i).getPosition().y == _bullets.at(it).getPosition().y){
//             _bullets.erase(_bullets.begin() + it);
//             ///aliens.erase(aliens.begin() + i);
//             
//             std::cout<<aliens.at(i).getPosition().y << " "<< _bullets.at(it).getPosition().y<<std::endl;
//            }
//         }
         
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

