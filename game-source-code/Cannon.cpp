#include "Cannon.hpp"
#include <iostream>


Cannon::Cannon()
{
    ///This should be refactored as the time goes on;
 _cannonSpeed = 320.f;
 cannonDown[0] =false;
 cannonDown[1] =false;
 _cannonLives = 3;
 if(!_texture[0].loadFromFile("../executables/resources/Laser_Cannon.png") ||
    !_texture[1].loadFromFile("../executables/resources/Laser_Cannonc.png") ){
     std::cerr<<"Could not load cannon shooter sprite"<<std::endl;
 }
 _cannon[0].setTexture(_texture[0]);
 _cannon[0].scale(sf::Vector2f(0.5 , 0.5));
 _cannon[1].setTexture(_texture[1]);
 _cannon[1].scale(sf::Vector2f(0.5 , 0.5));
 
//_position.x = 500.f;
//_position.y = 550.f;
// 
}

void Cannon::setInitPosOfCannon(sf::Vector2f _position){
    this->_position[0].x = _position.x/2;
    this->_position[0].y = _position.y-30.f;
    this->_position[1].x = _position.x/2;
    this->_position[1].y = 45.f;
    return;
}


//void Cannon::DrawCannon(sf::RenderWindow & _window){
//    cannonIsShot();
//    if(cannonDown[0] || cannonDown[1] )
//       return;
//    else 
//         _window.draw(_cannon[0]);
//}
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

void Cannon::moveRight(){
    if(_cannon[0].getPosition().x + 113/2 <  1000.f && (_cannon[0].getPosition().y >= 550.f ||
        _cannon[0].getPosition().y - 50/2 < 15.f))
        _moveRight = true;
    else _moveRight = false;
}


void Cannon::moveRightTop(){
    if(_cannon[1].getPosition().x + 113/2 <  1000.f )
        _moveRightTop = true;
    else _moveRightTop = false;
}


void Cannon::stopRight(){
    _moveRight = false;
}
void Cannon::stopRightTop(){
    _moveRightTop = false;
}

void Cannon::stopUp(){
    _moveUp = false;
}
void Cannon::StopLeftTop(){
    _moveLeftTop = false;
}

void Cannon::moveUp(){
//    _collide.lowerCannonBlocks(_defense, _cannon);
    if(_cannon[0].getPosition().y > 2.0f)
        _moveUp  = true;
    else _moveUp = false;
    
}



void Cannon::moveDown(){
    
    if(_cannon[0].getPosition().y + 0 <  570.f)
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
        for(auto it = 0u; it != _bullets.size(); ++it){
            if(abs(_bullets.at(it).getPosition().x - _cannon[itr].getPosition().x) <26 && 
                abs( _bullets.at(it).getPosition().y - _cannon[itr].getPosition().y) <26 && 
                orientation.at(it) == FiringDirection::down){
                    _cannonLives = _cannonLives -1;
            }
        }
    }
    std::cout<<_cannonLives<<std::endl;
    return;
}


int Cannon::getCannonLives() const{
    return _cannonLives;
}
Cannon::~Cannon()
{
}

