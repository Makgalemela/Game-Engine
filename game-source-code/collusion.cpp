#include "collusion.hpp"
#include <iostream>
collusion::collusion()
{
    
}


bool collusion::lowerCannonBlocks(const DefenseBlocks& def , sf::Sprite _cannon){
  
    auto[_blocks , _position] = def.Blocks();
    
//    sf::Sprite cannon = _cannon.getSprite();
    for(auto it = 0u ; it != _blocks.size(); ++it){
        if(abs(_blocks.at(it).getPosition().x -_cannon.getPosition().x) < 8.f && 
            abs(_blocks.at(it).getPosition().y -_cannon.getPosition().y) < 8.f  ){
            return true;
        }
    }
    return false;
}

collusion::~collusion()
{
}

