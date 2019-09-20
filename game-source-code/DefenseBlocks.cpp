#include "DefenseBlocks.hpp"
#include <iostream>
DefenseBlocks::DefenseBlocks()
{
    
    if(!_blockTexture.loadFromFile("../executables/resources/block.png") ||
      !_blockTexture2.loadFromFile("../executables/resources/blockc.png")){
        std::cerr<<"Failed to load plock sprite"<<std::endl;
    }
    
    _blockSprite.setTexture(_blockTexture);
    _blockSprite.scale(sf::Vector2f(0.7f , 0.3f));
    
    _blockSprite2.setTexture(_blockTexture2);
    _blockSprite2.scale(sf::Vector2f(0.7f , 0.3f));
    
    _position.x = 275.f;
    //_position.y = 540.f;
    _position.y = 75.f;
}

 std::tuple<std::vector<sf::Sprite> , sf::Vector2f> DefenseBlocks::Blocks() const {
     return{ _blocks ,  _position};
 }


void DefenseBlocks::loadBlocks(){
      for(auto it = 0 ; it < 8 ; ++it){
        if(it<4) _blocks.push_back(_blockSprite2);
        else _blocks.push_back(_blockSprite);
     }
     return;
}
DefenseBlocks::~DefenseBlocks()
{
}

