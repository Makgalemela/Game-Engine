#ifndef CANNON_HPP
#define CANNON_HPP

#include <SFML/Graphics.hpp>
#include "collusion.hpp"
#include "DefenseBlocks.hpp"
#include "Bullet.hpp"
#include <tuple>
//***************************************************************
//
//
//this class load and create and cannon which shots the bullets
//
//
//************************************************************


class Cannon : public Bullet
{
public:
    Cannon();
    ~Cannon();
    
    
    
    
//    **************************************
//    
//    this method return spalshscreen object
//    
//    \param return sprite
//    ***************************************
    sf::Sprite getSprite() const;
    sf::Sprite getSprite2() const;

//    **************************************
//    
//    this method initiate movement to the left
//    
//    \param return
//    ***************************************
    void moveLeft();
    void moveLeftTop();
    
    
    
//    **************************************
//    
//    this method initiate movement to the right
//    
//    \param return
//    ***************************************
    void moveRight();
    void moveRightTop();
    
//    **************************************
//    
//    this method initiate stops movement to the left
//    
//    \param return
//    ***************************************
    void StopLeft();
    void StopLeftTop();
    
    
//    **************************************
//    
//    this method initiate stops movement to the right
//    
//    \param return
//    ***************************************
    void stopRight();
    void stopRightTop();
    
    
    
    
//    **************************************
//    
//    this method initiate movement to the top
//    
//    \param return
//    ***************************************
    void moveUp();
    
    
    
    
//    **************************************
//    
//    this method initiate movement to the bottom
//    
//    \param return
//    ***************************************

    void moveDown();
    
    
//    **************************************
//    
//    this method initiate stops movement to the bottom
//    
//    \param return
//    ***************************************
    void stopDown();
    
    
//    **************************************
//    
//    this method initiate stops movement to the top
//    
//    \param return
//    ***************************************
    void stopUp();
    void rotate();
   // void anotherMove(Direction direction);
   
   
//    **************************************
//    
//    update the time
//    
//    \param return
//    ***************************************
    void update(float elaspseTime);

//    **************************************
//    
//    return the position of the cannon
//    
//    \param return sf::Vector2f
//    ***************************************
    sf::Vector2f getCannon2CenterFirePosition() const;
    sf::Vector2f getCannonCenterFirePosition() const;
    
    void setInitPosOfCannon(sf::Vector2f _position);
    void cannonIsShot();
    void DrawCannon(sf::RenderWindow & _window);
    
    
    int getCannonLives() const;
private: 
    //first cannon
    sf::Vector2f _position[2];
    sf::Sprite _cannon[2];
    sf::Texture _texture[2];
    bool cannonDown[2];
    
    //Direction direction;
    bool _moveLeft;
    bool _moveRight;
    bool _moveLeftTop;
    bool _moveRightTop;
    bool _moveUp;
    bool _moveDown;
    float _cannonSpeed;
    int _cannonLives;
    DefenseBlocks _defense;
};

#endif // CANNON_HPP
