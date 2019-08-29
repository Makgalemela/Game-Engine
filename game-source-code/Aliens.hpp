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
private:
    sf::Texture _alienTexture;
    sf::Sprite _alienSprite;
    vector<sf::Sprite> aliens;
    sf::Vector2f _position;
};

#endif // ALIENS_HPP
