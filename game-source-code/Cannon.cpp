#include "Cannon.hpp"
#include <iostream>
Cannon::Cannon()
{
    ///This should be refactored as the time goes on;
    
 _cannonSpeed = 320.f;
 if(!_texture.loadFromFile("../executables/resources/Laser_Cannon.png")){
     std::cerr<<"Could not load cannon shooter sprite"<<std::endl;
 }
 _cannon.setTexture(_texture);
 _cannon.scale(sf::Vector2f(0.5 , 0.5));
 
_position.x = 400.f;
_position.y = 695.f;
 
 
}



sf::Sprite Cannon::getSprite() const{
    return _cannon;
}

void Cannon::moveLeft(){
    if(_cannon.getPosition().x >  15.f && (_cannon.getPosition().y >= 650.f || _cannon.getPosition().y - 50/2 < 15.f))
        _moveLeft = true;
    else _moveLeft = false;
}

void Cannon::moveRight(){
    if(_cannon.getPosition().x + 113/2 <  800.f && (_cannon.getPosition().y >= 650.f || _cannon.getPosition().y - 50/2 < 15.f))
        _moveRight = true;
    else _moveRight = false;
}

void Cannon::stopRight(){
    _moveRight = false;
}

void Cannon::moveUp(){
    
    if(_cannon.getPosition().y > 2.0f)
        _moveUp  = true;
    else _moveUp = false;
}

void Cannon::stopUp(){
    _moveUp = false;
}


void Cannon::moveDown(){
    
    if(_cannon.getPosition().y + 62/2 <  720.f)
        _moveDown = true;
    else _moveDown = false;
}

void Cannon::stopDown(){
    _moveDown = false;
}
void Cannon::StopLeft(){
    _moveLeft = false;
}

void Cannon::update(float elapsedTime){
    if(_moveLeft)
        _position.x -= _cannonSpeed*elapsedTime;
        
    else if(_moveRight)
        _position.x += _cannonSpeed*elapsedTime;
    
    else if(_moveUp)
        _position.y -= _cannonSpeed*elapsedTime;
        
    else if(_moveDown)
        _position.y += _cannonSpeed*elapsedTime;
       
    rotate();
    _cannon.setPosition(_position);
}



sf::Vector2f Cannon::getCannonCenterFirePosion() const {
    return _position;
}


void Cannon::rotate(){
    
    if( _cannon.getPosition().y < 10.0f){
        _cannon.setRotation(360.f);
    }
}
///trial function


Cannon::~Cannon()
{
}

