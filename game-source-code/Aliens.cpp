
#include "Aliens.hpp"

Aliens::Aliens()
{
    _alienTexture.loadFromFile("../executables/resources/aliens.png");
    _alienSprite.setTexture(_alienTexture);
     _alienSprite.scale(sf::Vector2f(0.035f , 0.035f));
     _position.x = 150.f;
     _position.y = 300.f;
}

tuple<vector<sf::Sprite> , sf::Vector2f> Aliens::aliensSprite() const{
    return {aliens, _position};
}
void Aliens::loadAliens() {
    
    for(auto it = 0 ; it !=10 ; ++it){
         aliens.push_back(_alienSprite);
    }
    
}
Aliens::~Aliens()
{
}

