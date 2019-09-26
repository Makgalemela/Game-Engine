#ifndef CANNON_HPP
#define CANNON_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include "Entity.hpp"
#include <tuple>

/**
 * @class Cannon
 * @author Matome Makgalemela
 * @date 26/09/2019
 * @file Cannon.hpp
 * @brief The class instentiate the Cannon Object, the methods in this class
 *          The class extends Bullet class, this is because Cannon is the only
 *             Entity that means nothing without the bullets
 */

class Cannon : public Bullet 
{
public:

    /**
     * @brief This is constructor which instetiate the Cannon Object
     */
    
    Cannon();
    ~Cannon();
    /**
     * @brief The utility method return the sprite object which is essensially cannon1,
     *       cannon1, cannon at the bottom of the screen.
     */
    
    sf::Sprite getSprite() const;
    
    /**
     * @brief The utility method return the sprite object which is essensially cannon2,
     *       cannon2, cannon at the bottom of the screen.
     */
    sf::Sprite getSprite2() const;
    
    /**
     * @brief Utility function for the movement of the cannon object,   
     *          the move function is derived from an enterface, Entity.
     *          Cannon class overides the move function.
     * @param _dir The direction of movement of the Cannon ; Left, Right 
     * @param _id The cannon Identifier; UpperCannon or LowerCannon
     */
    
    
    void move(Direction _dir , EntityId _id) override;
    
     /**
     * @brief Utility function for Stopping movement of the cannon object,   
     *          the stopMove function is derived from an enterface, Entity.
     *          Cannon class overides the stopMove function.
     * @param _dir The direction of movement of the Cannon ; Left, Right 
     * @param _id The cannon Identifier; UpperCannon or LowerCannon
     */
    void stopMove(Direction _dir , EntityId _id) override;
    
    /**
     * @brief The class update the position of the Cannon, this is  done when
     *          the cannon movement is initiated.
     * @param elapsedTime This variable is the factor that isused to move the cannon
     *          object.
     */
    
    void update(const float& elapsedTime) override;
    
    /**
     * @brief The function return the current position of cannon1,
     *          cannon at bottom of the screen initially.
     */
    
    sf::Vector2f getCannon2CenterFirePosition() const;
    
     /**
     * @brief The function return the current position of cannon2,
     *          cannon at Top of the screen initially.
     */
     
    sf::Vector2f getCannonCenterFirePosition() const;
    
    /**
     * @brief The utility set the initial starting points of the two cannons
     *          
     * @param _position The start
     */
    
    
    void setInitPosOfCannon(sf::Vector2f _position);
    
    /**
     * @brief The utility function to check the collusion of the cannon object
     *          with bullet object. When the collusion happens both the cannon and,
     *          the bullet loses lives. The bullets is destroyed and cannon is give another
     *          chance if there is still live remaining
     */
    
    void cannonIsShot();
   
    /**
     * @brief The two cannons share lives, they both have three lives. If the cannon
     *          is shot or  collide with the object the cannons loses one live until
     *          no lives are left in which way the game ends and the player loses.
     */
    
    
    int getCannonLives() const;
    
    
    /**
     * @brief The method is inherited from the Entity Class, it is used to set the
     *          texture of the sprite object.  Cannon class overide this method.
     * @param _texture Texture argument,
     * @param _index A constant variable optionally used to determine the
     *          index of the texture, wherein the texture exist in an array
     */
    
    void setTexture(sf::Texture _texture ,const int& i) override;
private: 
    //first cannon
    sf::Vector2f _position[2];
    sf::Sprite _cannon[2];
    sf::Texture _texture[2];
    bool cannonDown[2];
    FiringDirection cannonOrientation[2];
    bool _moveLeft;
    bool _moveRight;
    bool _moveLeftTop;
    bool _moveRightTop;
    float _cannonSpeed;
    int _cannonLives;
};

#endif // CANNON_HPP
