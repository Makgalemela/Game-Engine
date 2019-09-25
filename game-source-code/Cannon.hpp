#ifndef CANNON_HPP
#define CANNON_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include "Entity.hpp"
#include <tuple>


class Cannon : public Bullet 
{
public:
    Cannon();
    ~Cannon();

    sf::Sprite getSprite() const;
    sf::Sprite getSprite2() const;
    void move(Direction _dir , EntityId _id) override;
    void stopMove(Direction _dir , EntityId _id) override;
    void update(const float& elapsedTime) override;
    sf::Vector2f getCannon2CenterFirePosition() const;
    sf::Vector2f getCannonCenterFirePosition() const;
    
    void setInitPosOfCannon(sf::Vector2f _position);
    void cannonIsShot();
    void DrawCannon(sf::RenderWindow & _window);
    int getCannonLives() const;
    void setTexture(sf::Texture _texture ,const int& i) override;
private: 
    //first cannon
    sf::Vector2f _position[2];
    sf::Sprite _cannon[2];
    sf::Texture _texture[2];
    bool cannonDown[2];
    FiringDirection cannonOrientation[2];
    //Direction direction;
    bool _moveLeft;
    bool _moveRight;
    bool _moveLeftTop;
    bool _moveRightTop;
    float _cannonSpeed;
    int _cannonLives;
};

#endif // CANNON_HPP
