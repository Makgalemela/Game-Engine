
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
     _position.x = 20.f;
     _position.y = 310.f;
     
     
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
     _positionu.x = 600.f;
     _positionu.y = 210.f;
    _changeAlienDirection = false;
}

tuple<vector<sf::Sprite> ,vector<sf::Sprite>> Aliens::aliensSprite() const{
    return {aliens,aliensu};
}

vector<sf::Sprite> Aliens::aliensSpriteAlone() const{
    return aliens;
}


void Aliens::loadAliens() {
    for(auto it = 0 ; it !=30; ++it){
        if(it < 10){
            aliens.push_back(_alienSprite2);
            aliensu.push_back(_alienSpriteu);
            isAlive.push_back(true);
            isAlive2.push_back(true);
        }
        else if(it < 20){
            aliens.push_back(_alienSprite3);
            aliensu.push_back(_alienSprite3u);
            isAlive.push_back(true);
            isAlive2.push_back(true);
        }
        else{
             aliens.push_back(_alienSprite);
             aliensu.push_back(_alienSprite2u);
             isAlive.push_back(true);
             isAlive2.push_back(true);
        }
    }
}


void Aliens::AlienMovement(sf::RenderWindow &_windows){
   if(_watch.timerForMovement()){
      if(!_changeAlienDirection){
        if(_position.x >= 950.f){
            _changeAlienDirection = true;
            _position.y += 30.f;
            _positionu.y -= 30.f;
            }
            update(40.f);
        }
        
    else {
        if(_position.x <= 5.f){
            _changeAlienDirection = false;
            _position.y += 30.f;
            _positionu.y -= 30.f;
        }
            update(-40.f);
        }
    }
}
   



void Aliens::alienIsShot(const int& index, const AliensDirection& ad){
    if(ad == AliensDirection::DownFace){
        if(aliens.at(index).getTexture() == &_alienTexture)
            _score.setScore(Scores::Ten);
        else if(aliens.at(index).getTexture() == &_alienTexture3)
            _score.setScore(Scores::Twenty);
        else if(aliens.at(index).getTexture() == &_alienTexture2)
            _score.setScore(Scores::ThirtyFive);
        isAlive.at(index) = false;
    }
    
    else if(ad == AliensDirection::UpFace){
        if(aliensu.at(index).getTexture() == &_alienTextureu)
            _score.setScore(Scores::Ten);
        else if(aliensu.at(index).getTexture() == &_alienTexture3u)
            _score.setScore(Scores::Twenty);
        else if(aliensu.at(index).getTexture() == &_alienTexture2u)
            _score.setScore(Scores::ThirtyFive);
         isAlive2.at(index) = false;
    }
   
}


void Aliens::setAlienPosition(){
    for(auto it = 0u; it != aliens.size(); ++it){
        if(it == 10 || it == 20){
            _position.x -=400.f;
            _position.y +=35.f;
            _positionu.x -=400.f;
            _positionu.y +=35.f;
        }
        aliens.at(it).setPosition(_position);
        aliensu.at(it).setPosition(_positionu);
        _position.x +=40.f;
        _positionu.x +=40.f;
    }
    return;
}

 void Aliens::update(const float& _pixel){
       for(auto it = aliens.begin(); it != aliens.end(); ++it){
             _position.x = (*it).getPosition().x+ _pixel;
            (*it).setPosition(_position);
       }
       for(auto it = aliensu.begin(); it != aliensu.end(); ++it){
             _positionu.x = (*it).getPosition().x-_pixel;
            (*it).setPosition(_positionu);
       }
     return;
 }
 
 
 bool Aliens::getIsAlive(const int& it , const AliensDirection& dir) const{
     if(dir == AliensDirection::DownFace)
        return isAlive.at(it);
    else return isAlive2.at(it);
 }
Aliens::~Aliens()
{
}

