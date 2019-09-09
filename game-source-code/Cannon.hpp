#ifndef CANNON_HPP
#define CANNON_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

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
//  / *enum class Direction {
//        Left,
//        Right,
//        Up,
//        Down
//        };
//        */


//    **************************************
//    
//    this method initiate movement to the left
//    
//    \param return
//    ***************************************
    void moveLeft();
    
    
    
//    **************************************
//    
//    this method initiate movement to the right
//    
//    \param return
//    ***************************************
    void moveRight();
    
//    **************************************
//    
//    this method initiate stops movement to the left
//    
//    \param return
//    ***************************************
    void StopLeft();
    
    
//    **************************************
//    
//    this method initiate stops movement to the right
//    
//    \param return
//    ***************************************
    void stopRight();
    
    
    
    
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
    sf::Vector2f getCannonCenterFirePosion() const;
    
    void setInitPosOfCannon(sf::Vector2f _position);
    
private: 
    sf::Vector2f _position;
    sf::Sprite _cannon;
    sf::Texture _texture;
    //Direction direction;
    bool _moveLeft;
    bool _moveRight;
    bool _moveUp;
    bool _moveDown;
    float _cannonSpeed;

};

#endif // CANNON_HPP
