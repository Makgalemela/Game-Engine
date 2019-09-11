
#include "Aliens.hpp"
#include <iostream>

Aliens::Aliens()
{
    if(!_alienTexture.loadFromFile("../executables/resources/aliens.png") || 
    !_alienTexture2.loadFromFile("../executables/resources/alien2.png")||
    !_alienTexture3.loadFromFile("../executables/resources/alien3.png")){
        std::cout<<"One more aliens sprite could not load"<<std::endl;
    }
    _alienSprite.setTexture(_alienTexture);
     _alienSprite.scale(sf::Vector2f(0.045f , 0.045f));
     
    // _alienTexture2.loadFromFile("../executables/resources/alien2.png");
     _alienSprite2.setTexture(_alienTexture2);
     _alienSprite2.scale(sf::Vector2f(0.035f , 0.035f));
     
    // _alienTexture3.loadFromFile("../executables/resources/alien3.png");
     _alienSprite3.setTexture(_alienTexture3);
     _alienSprite3.scale(sf::Vector2f(0.040f , 0.040f));
     _position.x = 240.f;
     _position.y = 350.f;
     
     
     //upper positioned aliens
     
      if(!_alienTextureu.loadFromFile("../executables/resources/aliensc.png") || 
    !_alienTexture2u.loadFromFile("../executables/resources/alien2c.png")||
    !_alienTexture3u.loadFromFile("../executables/resources/alien3c.png")){
        std::cout<<"One more aliens sprite could not load"<<std::endl;
    }
    _alienSpriteu.setTexture(_alienTextureu);
     _alienSpriteu.scale(sf::Vector2f(0.045f , 0.045f));
     
    // _alienTexture2.loadFromFile("../executables/resources/alien2.png");
     _alienSprite2u.setTexture(_alienTexture2u);
     _alienSprite2u.scale(sf::Vector2f(0.035f , 0.035f));
     
    // _alienTexture3.loadFromFile("../executables/resources/alien3.png");
     _alienSprite3u.setTexture(_alienTexture3u);
     _alienSprite3u.scale(sf::Vector2f(0.040f , 0.040f));
     _positionu.x = 240.f;
     _positionu.y = 200.f;
}

tuple<vector<sf::Sprite> ,vector<sf::Sprite>,sf::Vector2f ,sf::Vector2f> Aliens::aliensSprite() const{
    return {aliens,aliensu, _position, _positionu};
}

vector<sf::Sprite> Aliens::aliensSpriteAlone() const{
    return aliens;
}


void Aliens::loadAliens() {
    for(auto it = 0 ; it !=54; ++it){
        if(it < 18){
            aliens.push_back(_alienSprite2);
            aliensu.push_back(_alienSpriteu);
        }
        else if(it < 36){
            aliens.push_back(_alienSprite3);
            aliensu.push_back(_alienSprite3u);
        }
        else{
             aliens.push_back(_alienSprite);
             aliensu.push_back(_alienSprite2u);
        }
         
    }
    
}


void Aliens::AlienMovement(){
    for(auto it =  0u; it != aliens.size() ; ++it){
            aliens.at(it).move(0, -20.f);
            if(_position.x > 10){
                _position.x-=1;
            }
    }
}
Aliens::~Aliens()
{
}

