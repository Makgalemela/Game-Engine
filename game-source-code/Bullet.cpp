#include "Bullet.hpp"
#include <iostream>
Bullet::Bullet()
{
   
    _bulletSpeed = 0.55f;
    _bulletExplosionSprite.setTexture(_bulletExplosionTexture);
    _bulletExplosionSprite.scale(0.1f , 0.1f);
}


void Bullet::setTexture(sf::Texture _texture, const int& _index){
    _bulletTexture = _texture;
    _bulletSprite.setTexture(_bulletTexture);
    _bulletSprite.scale(0.02f , 0.02f);
    return;
}

void Bullet::startFiring(const FiringDirection& fd, sf::Vector2f _bulletPosition){
     if(fd == FiringDirection::up)
         _bulletPosition.y = _bulletPosition.y-25.f; 
    else
         _bulletPosition.y = _bulletPosition.y+25.f; 

     _bulletPosition.x += 18.f;
    _bulletSprite.setPosition(_bulletPosition);
    _bullets.push_back(_bulletSprite);
      bulletOrientation.push_back(fd);
     
    return;
}

 void Bullet::BulletOutOfScreen( ){
     for(auto it = 0u ; it < _bullets.size() ; ++it){
         if(_bullets.size() != 0)
            if( _bullets.at(it).getPosition().y < 50.f || _bullets.at(it).getPosition().y > 570.f){
                 _bullets.erase(_bullets.begin() + it);
                bulletOrientation.erase(bulletOrientation.begin() +it);
            }
     }
    return;
 }
 

 void Bullet::BulletsCollusion(sf::RenderWindow& _window){
     for(auto it = 0u; it != _bullets.size(); ++it){
         for(auto i = 0u; i != _bullets.size();++i ){
             if( _bullets.size() != 0 && i != it)
             if( abs(_bullets.at(i).getPosition().x - _bullets.at(it).getPosition().x)<5 &&
                abs(_bullets.at(i).getPosition().y - _bullets.at(it).getPosition().y)<5){
              _bullets.erase(_bullets.begin()+ it);
              _bullets.erase(_bullets.begin()+ i);
              i--;
              bulletOrientation.erase(bulletOrientation.begin() +it);
              bulletOrientation.erase(bulletOrientation.begin()+i);
              return;
            }
         }
     }
     return;
 }
 
 
 
void Bullet::fireBullet(sf::RenderWindow &_window )
{  
    for(auto it =  0u; it != _bullets.size() ; ++it){
         if(bulletOrientation.at(it) == FiringDirection::up)
                _bullets.at(it).move(0, -_bulletSpeed);
        else if(bulletOrientation.at(it) == FiringDirection::down) 
            _bullets.at(it).move(0, _bulletSpeed);
        _window.draw(_bullets.at(it));
    }
}

bool Bullet::alienShoot(sf::Sprite _alien , AliensDirection dir){
    float _posX = _alien.getPosition().x;
    float _posY = _alien.getPosition().y;
    
    for(auto it = 0u; it != _bullets.size(); ++it){
        if(abs(_bullets.at(it).getPosition().x - _posX) <20.f 
            && abs(_bullets.at(it).getPosition().y - _posY) <20.f){
            _bullets.erase(_bullets.begin()+it);
            bulletOrientation.erase(bulletOrientation.begin() +it);
            return true;
        }
    }

    return false;
}





tuple<std::vector<sf::Sprite>*, vector<FiringDirection>*> Bullet::getBullets(){
    return {&_bullets, &bulletOrientation};
}
Bullet::~Bullet()
{
}

