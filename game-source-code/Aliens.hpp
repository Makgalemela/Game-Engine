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
 * @author User
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
     *          the state of aliens at the later stage.
     */
    
    tuple<vector<sf::Sprite> ,vector<sf::Sprite>> aliensSprite() const;
    std::vector<sf::Sprite> aliensSpriteAlone() const;
    void alienIsMoving(sf::RenderWindow &_windows);
    void setAlienPosition();
    void alienIsShot(const int& it, const AliensDirection& ad = AliensDirection::DownFace);
    bool IsAlienAlive(const int& it, const AliensDirection& dir) const;
    bool aliensAtBottonOrTop() const;
    bool allAliensKilled() const;
    void scale();
    int getSize();
    void setTexture(sf::Texture _texture, const int& _index =0) override;
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
