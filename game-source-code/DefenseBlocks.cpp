#include "DefenseBlocks.hpp"
#include <iostream>
DefenseBlocks::DefenseBlocks()
{
    
    if(!_blockTexture.loadFromFile("../executables/resources/block.png")){
        std::cerr<<"Failed to load plock sprite"<<std::endl;
    }
    
    _blockSprite.setTexture(_blockTexture);
    _blockSprite.scale(sf::Vector2f(1.f , 0.5f));
    _position.x = 150.f;
    _position.y = 610.f;
}

 std::tuple<std::vector<sf::Sprite> , sf::Vector2f> DefenseBlocks::Blocks() const {

     return{ _blocks ,  _position};
 }


void DefenseBlocks::loadBlocks(){
      for(auto it = 0 ; it < 4 ; ++it){
          _blocks.push_back(_blockSprite);
     }
     return;
}
DefenseBlocks::~DefenseBlocks()
{
}

