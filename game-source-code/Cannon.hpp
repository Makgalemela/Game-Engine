#ifndef CANNON_HPP
#define CANNON_HPP

#include <SFML/Graphics.hpp>


class Cannon
{
public:
    Cannon();
    ~Cannon();
    
    sf::Sprite getSprite() const;
    
    void moveLeft();
    void moveRight();
    void StopLeft();
    void stopRight();
    void update(float elaspseTime);
private: 
    sf::Vector2f _position;
    sf::Sprite _sprite;
    sf::Texture _texture;
    
    bool _moveLeft;
    bool _moveRight;
    float _cannonSpeed;

};

#endif // CANNON_HPP
