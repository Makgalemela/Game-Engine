#include "Cannon.hpp"

Cannon::Cannon()
{
    ///This should be refactored as the time goes on;
    
 _cannonSpeed = 320;
 _texture.loadFromFile("../executables/resources/Laser_Cannon.png");
 _sprite.setTexture(_texture);
 
_position.x = 200;
_position.y = 200;
 
 
}

sf::Sprite Cannon::getSprite() const{
    return _sprite;
}

void Cannon::moveLeft(){
    _moveLeft = true;
}

void Cannon::moveRight(){
    _moveRight = true;
}

void Cannon::stopRight(){
    _moveRight = false;
}

void Cannon::StopLeft(){
    _moveLeft = false;
}

void Cannon::update(float elapsedTime){
    if(_moveLeft)
        _position.x -= _cannonSpeed*elapsedTime;
        
    else if(_moveRight)
        _position.x += _cannonSpeed*elapsedTime;
        
    _sprite.setPosition(_position);
}
Cannon::~Cannon()
{
}

