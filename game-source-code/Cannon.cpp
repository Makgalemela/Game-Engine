#include "Cannon.hpp"

Cannon::Cannon()
{
    ///This should be refactored as the time goes on;
    
 _cannonSpeed = 320;
 _texture.loadFromFile("../executables/resources/Laser_Cannon.png");
 _cannon.setTexture(_texture);
 
_position.x = 400;
_position.y = 635;
 
 
}

sf::Sprite Cannon::getSprite() const{
    return _cannon;
}

void Cannon::moveLeft(){
    if(_cannon.getPosition().x >  0.f)
        _moveLeft = true;
    else _moveLeft = false;
}

void Cannon::moveRight(){
    if(_cannon.getPosition().x + 113/2 <  753.f)
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
       
    rotate();
    _cannon.setPosition(_position);
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

