#ifndef ALIENS_HPP
#define ALIENS_HPP
#include <vector>
#include <tuple>
#include <SFML/Graphics.hpp>
#include "StopWatch.h"
#include "Score.hpp"
#include "Entity.hpp"
#include "ResourceManager.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;
enum class AliensDirection{
    UpFace =0,
    DownFace
    
};

/**
 * @class Aliens
 * @author Rachel Mvelase
 * @date 24/09/2019
 * @file Aliens.hpp
 * @brief The class implement the methods that contruct the Alien objects
 *        and is derived from the Entity class,
 */

class Aliens :public Entity
{
public:

    /**
     * @brief Aliens() is the default contructor of the alien object, the function
     *          is responsible for instantiation of the alien object.
     */
    
    Aliens();
    ~Aliens();
    
    /**
     * @brief The utility function load the aliens and queue them to be drawn on the 
     *      screen.This is done by pushing alien objects inside  the vector in the pre-
     *         determined order. This is essential for the presentation fo the the aliens
     */
    
    void loadAliens();
    
    /**
     * @brief The utility function is used to get the alien objects in terms of the 
     *          sprite. The alien of objects return by this function can be used to query
     *          the state of aliens at the later stage. This function return to vectors 
     *          because the aliens are store in the adjascent list.
     */
    
    tuple<vector<sf::Sprite> ,vector<sf::Sprite>> aliensSprite() const;
    
    /**
     * @brief The utility function to get the vector of aliens of aliens, this 
     *          is done to query the state of the group of aliens.
     */
    
    std::vector<sf::Sprite> aliensSpriteAlone() const;
    
    /**
     * @brief This utility function provid the functionality to allow the alien object to have 
     *          mobility across the game screen.
     * @param _windows object to allows the aliens to b drawn at the nre position.
     */
    
    void alienIsMoving(sf::RenderWindow &_windows);
    /**
     * @brief The functions role is to set the initial points for all aliens
     *          this is done to allow the aleins in the array of vectors to know
     *          Their initial position before they are drawn on the screen.
     */
    
    void setAlienPosition();
    
    /**
     * @brief The function is resposible for facilitating the interaction of the alien
     *          objects  and the bullet object. This also fucilitate the destroying of
     *          alien and bullet object. This is mainly to facilitate the scoring system
     *          
     * @param it index of the bullets as determined.
     * @param ad The direction the alien is facing.
     */
    
    void alienIsShot(const int& it, const AliensDirection& ad = AliensDirection::DownFace);
    /**
     * @brief The utility function to query the state of the alien object, alive or dead.
     * @param it  Index of the aliens being queried.
     * @param dir Dirirction the alien is facing.
     */
    
    bool IsAlienAlive(const int& it, const AliensDirection& dir) const;
    
    /**
     * @brief The utility function to query whether the aliens have invadeed the space of the 
     *      cannon object
     */
    
    bool aliensAtBottonOrTop() const;
    
    /**
     * @brief The utility function to query whether the alien object has been killed, this 
     *          is return true when the alien object interect with the bullet object
     */
    
    bool allAliensKilled() const;
    
    /**
     * @brief The alien objects are laoded as different sizes, they are then resized to 
     *      appear approprietly on the screen
     */
    
    void scale();
    
    /**
     * @brief The utility function return the size of the aliens which are alive
     *          this is essential when the aliens are required to shoot randomly, 
     *          only the aliens which are alive can shoot randomly.
     */
    
    
    int getSize();
    
    /**
     * @brief The method is inherited from the Entity Class, it is used to set the
     *          texture of the sprite object.  Aliens class overide the method.
     * @param _texture Texture argument,
     * @param _index A constant variable optionally used to determine the
     *          index of the texture, wherein the texture exist in an array
     */
    void setTexture(sf::Texture _texture, const int& _index =0) override;
    
    /**
     * @brief The tuple function returns the firing position of the aliens object
     *         and the orientation of the the firing alien
     * @param itr index of the firing alien.
     */
    
    tuple<sf::Vector2<float> ,bool, AliensDirection > getAlienFiringPosition(const int& itr );
private:
    sf::Texture alienTexture[6];
    sf::Sprite alienSprite[6];
    std::vector<sf::Sprite> aliens[2];
    sf::Vector2f _position[2];
    bool _changeAlienDirection[2];
    StopWatch _watch;
    Score _score;
    std::vector<bool> alienIsAlive[2];
    std::vector<AliensDirection> alienOrientation[2];
    ResourceManager _rm;
    void setTexture();
    
    void update(const float& _pixel, const int& i);
    void updateRows(const int& i);
  
};

#endif // ALIENS_HPP
