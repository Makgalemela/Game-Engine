#ifndef CANNON_HPP
#define CANNON_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class Cannon : public Bullet
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
    
    sf::Vector2f getCannonCenterFirePosion() const;
    
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
