#include "Cannon.hpp"
#include <iostream>


Cannon::Cannon()
{
    _cannonSpeed = 320.f;
    cannonDown[0] =false;
    cannonDown[1] =false;
    _cannonLives = 3;
    cannonOrientation[0] = FiringDirection::up;
    cannonOrientation[1] = FiringDirection::down; 
}


void Cannon::setCannons(sf::Texture _texture ,const int& i){
    this->_texture[i] = _texture; 
     _cannon[i].setTexture(this->_texture[i]);
    _cannon[i].scale(sf::Vector2f(0.5 , 0.5));
}

void Cannon::setInitPosOfCannon(sf::Vector2f _position){
    this->_position[0].x = _position.x/2;
    this->_position[0].y = _position.y-30.f;
    this->_position[1].x = _position.x/2;
    this->_position[1].y = 45.f;
    return;
}


sf::Sprite Cannon::getSprite() const{
    return _cannon[0];
}
sf::Sprite Cannon::getSprite2() const{
    return _cannon[1];
}

void Cannon::moveLeft(){
    if(_cannon[0].getPosition().x >  15.f && (_cannon[0].getPosition().y >= 550.f ||
        _cannon[0].getPosition().y - 50/2 < 15.f))
        _moveLeft = true;
    else _moveLeft = false;
}

void Cannon::moveLeftTop(){
    if(_cannon[1].getPosition().x >  15.f)
        _moveLeftTop = true;
    else _moveLeftTop = false;
}

//void Cannon::moveRight(){
//    if(_cannon[0].getPosition().x + 113/2 <  1000.f && (_cannon[0].getPosition().y >= 550.f ||
//        _cannon[0].getPosition().y - 50/2 < 15.f))
//        _moveRight = true;
//    else _moveRight = false;
//}




 void Cannon::move(Direction _dir , EntityId _Id){
     
     if(_Id == EntityId::Cannon1){
         if(_dir ==Direction::Right && _cannon[0].getPosition().x + 113/2 <  1000.f && 
            (_cannon[0].getPosition().y >= 550.f ||_cannon[0].getPosition().y - 50/2 < 15.f))
            _moveRight = true;
         else if(_dir ==Direction::Left&&_cannon[0].getPosition().x >  15.f && 
            (_cannon[0].getPosition().y >= 550.f ||_cannon[0].getPosition().y - 50/2 < 15.f))
                _moveLeft = true;
     }
     else if( _Id  ==EntityId::Cannon2){
         if(_dir ==Direction::Right && _cannon[1].getPosition().x + 113/2 <  1000.f )
                _moveRightTop = true;
                
        else if(_dir ==Direction::Left&& _cannon[1].getPosition().x >  15.f)
                    _moveLeftTop = true;
    }else{
        _moveRight = false;
        _moveLeft = false;
        _moveLeftTop = false;
        _moveRightTop = false;
    }
     
    return;
 }


 void Cannon::stopMove(Direction _dir , EntityId _id){
     
     if(_id == EntityId::Cannon1){
         if(_dir == Direction::Left)
             _moveLeft = false;
         if(_dir == Direction::Right)
             _moveRight = false;
     }
     
     else if(_id == EntityId::Cannon2){
         if(_dir == Direction::Left)
             _moveLeftTop = false;
         if(_dir == Direction::Right)
             _moveRightTop = false;
     }
 }


void Cannon::update(float elapsedTime){
    if(_moveLeft)
        _position[0].x -= _cannonSpeed*elapsedTime;
        
    else if(_moveRight)
        _position[0].x += _cannonSpeed*elapsedTime;
        
     if(_moveLeftTop)
        _position[1].x -= _cannonSpeed*elapsedTime;
        
    else if(_moveRightTop)
        _position[1].x += _cannonSpeed*elapsedTime;
    
    else if(_moveUp)
        _position[0].y -= _cannonSpeed*elapsedTime;
        
    else if(_moveDown)
        _position[0].y += _cannonSpeed*elapsedTime;
        
    _cannon[0].setPosition(_position[0]);
    _cannon[1].setPosition(_position[1]);
}



sf::Vector2f Cannon::getCannonCenterFirePosition() const {
     return _position[0];
}

sf::Vector2f Cannon::getCannon2CenterFirePosition() const {
     return _position[1];
}

void Cannon::rotate(){
    
    if( _cannon[0].getPosition().y < 10.0f){
        _cannon[0].setRotation(360.f);
    }
}
///trial function


void Cannon::cannonIsShot(){
    auto [_bullets, orientation] = getBullets();
    for(auto itr = 0u ; itr != 2 ; ++itr){
        for(auto it = 0u; it != _bullets->size(); ++it){
            if(abs(_bullets->at(it).getPosition().x - _cannon[itr].getPosition().x) <=20 && 
                abs( _bullets->at(it).getPosition().y - _cannon[itr].getPosition().y) <=20 && 
                        orientation->at(it) != cannonOrientation[itr]){
                    _bullets->erase(_bullets->begin() + it);
                    orientation->erase(orientation->begin() +it);
                    _cannonLives = _cannonLives -1;
                    return;
            }
        }
    }
    return;
}


int Cannon::getCannonLives() const{
    return _cannonLives;
}
Cannon::~Cannon()
{
}

