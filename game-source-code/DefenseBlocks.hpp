#ifndef DEFENSEBLOCKS_HPP
#define DEFENSEBLOCKS_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>
//#include "collusion.hpp"

//****************************************************************
//This class load and create the blocks which shield the cannon from the fire power of aliens
//*****************************************************************

class DefenseBlocks
{
public:
    DefenseBlocks();
    ~DefenseBlocks();
//    *******************************************************
//    Utility function returns vector of Blocks
//    and the postion where they are start on each other
//    this position is the start position where the blocks will be draw
//    param tuple<vector, vector?
//    ******************************************************
    std::tuple<std::vector<sf::Sprite> , sf::Vector2f> Blocks() const;
    
    void loadBlocks();
private:
    
    sf::Sprite _blockSprite;
    sf::Texture _blockTexture;
    sf::Sprite _blockSprite2;
    sf::Texture _blockTexture2;
    std::vector<sf::Sprite> _blocks;
    sf::Vector2f _position;
};

#endif // DEFENSEBLOCKS_HPP
