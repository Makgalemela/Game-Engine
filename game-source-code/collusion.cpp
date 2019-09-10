#include "collusion.hpp"
#include <iostream>
collusion::collusion()
{
    
}


bool collusion::lowerCannonBlocks(const DefenseBlocks& def , const Cannon & _cannon){
  
    auto[_blocks , _position] = def.Blocks();
    sf::Sprite cannon = _cannon.getSprite();
    for(auto it = 0u ; it != _blocks.size(); ++it){
        if(cannon.getGlobalBounds().intersects(_blocks.at(it).getGlobalBounds())){
            std::cout<<"Bumped"<<std::endl;
            //_cannon.const_cast<Cannon*> (this)->stopUp();
           /// _cannon.stopUp();
            return true;
        }
    }
    return false;
}

collusion::~collusion()
{
}

