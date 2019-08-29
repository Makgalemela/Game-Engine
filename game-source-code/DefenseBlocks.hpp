#ifndef DEFENSEBLOCKS_HPP
#define DEFENSEBLOCKS_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>
class DefenseBlocks
{
public:
    DefenseBlocks();
    ~DefenseBlocks();
    
    std::tuple<std::vector<sf::Sprite> , sf::Vector2f> Blocks() const;
    
    void loadBlocks();
private:

    sf::Sprite _blockSprite;
    sf::Texture _blockTexture;
    std::vector<sf::Sprite> _blocks;
    sf::Vector2f _position;
    
};

#endif // DEFENSEBLOCKS_HPP
