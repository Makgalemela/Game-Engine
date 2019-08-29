#ifndef ALIENS_HPP
#define ALIENS_HPP
#include <vector>
#include <tuple>
#include <SFML/Graphics.hpp>
using namespace std;
class Aliens
{
public:
    Aliens();
    ~Aliens();
    
    void loadAliens();
    tuple<vector<sf::Sprite> , sf::Vector2f> aliensSprite() const;
    std::vector<sf::Sprite> aliensSpriteAlone() const;
private:
    sf::Texture _alienTexture;
    sf::Texture _alienTexture2;
    sf::Texture _alienTexture3;
    sf::Sprite _alienSprite;
    sf::Sprite _alienSprite2;
    sf::Sprite _alienSprite3;
    vector<sf::Sprite> aliens;
    sf::Vector2f _position;
};

#endif // ALIENS_HPP
