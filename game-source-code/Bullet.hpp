#ifndef BULLET_HPP
#define BULLET_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <tuple>
#include "StopWatch.h"
#include "Aliens.hpp"
#include "Entity.hpp"
#include <cstdlib>


enum class FiringDirection{
    up = 0,
    down,
    defaultd
};

/**
 * @class Bullet
 * @author Rachel Mvelase
 * @date 24/09/2019
 * @file Bullet.hpp
 * @brief The class describes the methods which gives the bullet objects its
 *          attributes, such as speed and direction as well the type of bullet.
 *          The class instentiate methods for the bullets collusion with other
 *          objects
 */



class Bullet : public Entity
{
public:
    /**
     * @brief This is default constructor, it's responsibility is to instentiate 
     *          the private member variable when the bullet object is created
     */
    
    Bullet();
    ~Bullet();
    /**
     * @brief  The utility method is called when the bullet object is fired
     *          it facilitate the positioning and the moving of the bullet
     *           on the game window. It is also resposible for drawing the bullet object 
     *           on the screen.
     * @param _window
     */
    
    void fireBullet(sf::RenderWindow &_window );
    
    /**
     * @brief Instentiate the firing of the bullet, the method set up the initial
     *          position to which the bullet is to be fired from and initiate the 
     *          direction the bullet is fired towards.
     * @param fd is the bullet firing diriction
     * @param _bulletPosition position the bullet is fired from.
     */
    
    void startFiring(const FiringDirection& fd,sf::Vector2f _bulletPosition);
    
    /**
     * @brief The utility method for checking for the bullet collusions
     *          when the bullets collide they are removed from the vector 
     *          of bullets.
     */

    void BulletsCollusion();
    /**
     * @brief The utility method destroys the bullets moving off the screen.
     */
    
    void BulletOutOfScreen();
    
    /**
     * @brief The methods is used to check if the bullets and the aliens are in the
     *           same point. If the the bullet and the alien object are on the same
     *            point, they are both destroyed and the size of the bullets vector
     *             is automatically adjusted.
     *            Aliens vector is not change. The aliens is marked as dead when it collide
     *              with the bullet.
     * @param _alien Alien object in of the type Sf::Sprite 
     * @param dir   Direction the alien is facing
     */
    
    bool alienShoot(sf::Sprite _alien, AliensDirection dir);
    
    /**
     * @brief Tuple function, it returns the bullet object and the 
     *          firing direction of the bullet.
     */
    
    std::tuple<std::vector<sf::Sprite>*, std::vector<FiringDirection>*> getBullets() ;
    
    /**
     * @brief The method is inherited from the \Entity Class, it is used to set the
     *          texture of the sprite object.  Bullet class overide the method.
     * @param _texture Texture argument,
     * @param _index A constant variable optionally used to determine the
     *          index of the texture, wherein the texture exist in an array
     */
    
    void setTexture(sf::Texture _texture, const int& _index =0) override;
    /**
     * @brief The utility function is responsible for returning the firing position
     *          of the alien object and also the orientation of the firing bullet
     *           encapsulated in the enum \Class \FiringDirection
     * @param _pos Firing position
     * @param orinetation Orientation the Aliens
     */
    
    void aliensFiring(sf::Vector2<float> _pos , AliensDirection orinetation);
private:
     Aliens _aliens;
     StopWatch _stopwatch;
     float _bulletSpeed;
     float _bulletTimer;
     float _ellaspsedTime;
     std::vector<bool> IsAlienBullet;
     std::vector<FiringDirection> bulletOrientation;
     sf::Vector2f _bulletPosition;
     sf::Sprite _bulletSprite;
     sf::Texture _bulletTexture;
     sf::Sprite _bulletExplosionSprite;
     sf::Texture _bulletExplosionTexture;
     std::vector<sf::Sprite> _bullets;
};

#endif // BULLET_HPP
