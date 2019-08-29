
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
     _position.x = 150.f;
     _position.y = 370.f;
}

tuple<vector<sf::Sprite> , sf::Vector2f> Aliens::aliensSprite() const{
    return {aliens, _position};
}

vector<sf::Sprite> Aliens::aliensSpriteAlone() const{
    return aliens;
}


void Aliens::loadAliens() {
    
    for(auto it = 0 ; it !=54; ++it){
        if(it < 18){
            aliens.push_back(_alienSprite);
        }
        else if(it < 36){
            aliens.push_back(_alienSprite2);
        }
        else{
             aliens.push_back(_alienSprite3);
        }
         
    }
    
}
Aliens::~Aliens()
{
}

