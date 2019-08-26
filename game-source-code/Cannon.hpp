#ifndef CANNON_HPP
#define CANNON_HPP

#include <SFML/Graphics.hpp>


class Cannon
{
public:
    Cannon();
    ~Cannon();
    
    sf::Sprite getSprite() const;
    enum class Direction {
        Left,
        Right,
        Up,
        Down
        };
    void moveLeft();
    void moveRight();
    void StopLeft();
    void stopRight();
    void moveUp();
    void moveDown();
    void stopDown();
    void stopUp();
    void rotate();
    void anotherMove(Direction direction);
    void update(float elaspseTime);
    
private: 
    sf::Vector2f _position;
    sf::Sprite _cannon;
    sf::Texture _texture;
    Direction direction;
    bool _moveLeft;
    bool _moveRight;
    bool _moveUp;
    bool _moveDown;
    float _cannonSpeed;

};

#endif // CANNON_HPP
