
#include "Aliens.hpp"
#include <iostream>

Aliens::Aliens()
{
   
     _position[0].x = 35.f;
     _position[0].y = 310.f;
     _position[1].x = 560.f;
     _position[1].y = 230.f;
    _changeAlienDirection[0] = false;
    _changeAlienDirection[1] = false;
}


void Aliens::setTexture(sf::Texture _texture, const int& _index){
    alienTexture[_index] = _texture;
    alienSprite[_index].setTexture(alienTexture[_index]);
    return;
}

void Aliens::scale(){
    alienSprite[0].scale(sf::Vector2f(0.045f , 0.045f));
    alienSprite[1].scale(sf::Vector2f(0.035f , 0.035f));
    alienSprite[2].scale(sf::Vector2f(0.040f , 0.040f));
    alienSprite[3].scale(sf::Vector2f(0.045f , 0.045f));
    alienSprite[4].scale(sf::Vector2f(0.035f , 0.035f));
    alienSprite[5].scale(sf::Vector2f(0.040f , 0.040f));
    return;
}

tuple<vector<sf::Sprite> ,vector<sf::Sprite>> Aliens::aliensSprite() const{
    return {aliens[0],aliens[1]};
}

vector<sf::Sprite> Aliens::aliensSpriteAlone() const{
    return aliens[0];
}


void Aliens::loadAliens() {
    scale();
    int i = 0;
    AliensDirection ad;
   for(auto itr = 0u ; itr != 2 ; ++itr){
       if(itr == 0) ad = AliensDirection::DownFace;
       else ad = AliensDirection::UpFace;
       
        for(auto it = 0 ; it !=30; ++it){
            if( i = itr; it < 10)
                aliens[itr].push_back(alienSprite[i]);
            else if(i = itr+2 ;it < 20)
                aliens[itr].push_back(alienSprite[i]);
            else if(i = itr+4 ;it >= 20)
                 aliens[itr].push_back(alienSprite[i]);
                 
            alienIsAlive[itr].push_back(true);
            alienOrientation[itr].push_back(ad);
        }
   }
    return;
}

int Aliens::getSize(){
    return alienIsAlive[0].size();
}
void Aliens::alienIsMoving(sf::RenderWindow &_windows){
   if(_watch.timerForMovement()){
      if(int i= 0;!_changeAlienDirection[0])
            update(+40.f,i);
        else 
            update(-40.f,i);
            
    if(int i = 1; !_changeAlienDirection[1])
            update(+40.f,i);
        else 
            update(-40.f,i);
    }
    return;
}
   

void Aliens::alienIsShot(const int& index, const AliensDirection& ad){
    if(ad == AliensDirection::DownFace){
        if(aliens[0].at(index).getTexture() == &alienTexture[0])
            _score.setScore(Scores::Ten);
        else if(aliens[0].at(index).getTexture() == &alienTexture[2])
            _score.setScore(Scores::Twenty);
        else if(aliens[0].at(index).getTexture() == &alienTexture[1])
            _score.setScore(Scores::ThirtyFive);
        alienIsAlive[0].at(index) = false;
    }
    
    else if(ad == AliensDirection::UpFace){
        if(aliens[1].at(index).getTexture() == &alienTexture[3])
            _score.setScore(Scores::Ten);
        else if(aliens[1].at(index).getTexture() == &alienTexture[5])
            _score.setScore(Scores::Twenty);
        else if(aliens[1].at(index).getTexture() == &alienTexture[4])
            _score.setScore(Scores::ThirtyFive);
         alienIsAlive[1].at(index) = false;
    }
    return;
}


void Aliens::setAlienPosition(){
    for(auto it = 0u; it != aliens[0].size(); ++it){
        if(it == 10 || it == 20){
            _position[0].x =_position[0].x-400.f;
            _position[0].y =_position[0].y+35.f;
            _position[1].x =_position[1].x-400.f;
            _position[1].y =_position[1].y+35.f;
        }
        aliens[0].at(it).setPosition(_position[0]);
        aliens[1].at(it).setPosition(_position[1]);
        _position[0].x = _position[0].x+40.f;
        _position[1].x = _position[1].x+40.f;
    }
    return;
}

 void Aliens::update(const float& _pixel, const int& i){
      
       for(auto it = 0u; it != aliens[i].size(); ++it){
           
         _position[i].x = aliens[i].at(it).getPosition().x+ _pixel;
         _position[i].y = aliens[i].at(it).getPosition().y;
         aliens[i].at(it).setPosition(_position[i]);
         
        if(_position[i].x < 45.f && alienIsAlive[i].at(it)){
              updateRows(i);
            _changeAlienDirection[i] = false;
        }
        else if(_position[i].x > 930.f && alienIsAlive[i].at(it)){
             updateRows(i);
            _changeAlienDirection[i] = true;
        }
    }
    return;
 }
 

 bool Aliens::IsAlienAlive(const int& it , const AliensDirection& dir) const{
     if(dir == AliensDirection::DownFace)
        return alienIsAlive[0].at(it);
    else return alienIsAlive[1].at(it);
 }
 
 

void Aliens::updateRows(const int& i){
    auto _direction = -8.f;
    if(i==0) _direction = 8.f;
    
    for(auto it = 0u; it != aliens[i].size(); ++it){
        _position[i].x = aliens[i].at(it).getPosition().x;
        _position[i].y = aliens[i].at(it).getPosition().y+ _direction;
         aliens[i].at(it).setPosition(_position[i]);
    }
    return;
}

bool Aliens::aliensAtBottonOrTop() const{
    for(auto i = 0u ; i != 2 ; ++i){
        for(auto it = 0u; it != aliens[i].size(); ++it){
       if((aliens[i].at(it).getPosition().y >=545.f || aliens[i].at(it).getPosition().y <= 75.f) 
           && alienIsAlive[i].at(it))
           return true;
        }
    }
    return false;
}

bool Aliens::allAliensKilled() const{
    for(auto it = 0u; it != aliens[0].size(); ++it){
       if(alienIsAlive[0].at(it) || alienIsAlive[1].at(it))
           return false;
    }
    return true;
}

tuple<sf::Vector2<float> , bool , AliensDirection> Aliens::getAlienFiringPosition(const int& itr){
    int index_;
    
    srand(time(0));
    index_ = rand()%aliens[itr].size();
    sf::Vector2<float> _pos;
    _pos.x = aliens[itr].at(index_).getPosition().x;
    _pos.y = aliens[itr].at(index_).getPosition().y;
    
    return {_pos ,alienIsAlive[itr].at(index_), alienOrientation[itr].at(index_)};
}

Aliens::~Aliens()
{
}


