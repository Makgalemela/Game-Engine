#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML/Graphics.hpp>

enum class Direction{
    
  Left = 0,
  Right  
};

enum class EntityId{
    Cannon1 = 0,
    Cannon2
};
/**
 * @class Entity
 * @author Rachel
 * @date 26/09/2019
 * @file Entity.hpp
 * @brief The class provide an interface for the Entities. The methods are virtual
 *          and are overrriden by the classes which instantiate the Entities.
 */


class Entity
{
public:
    Entity();
    ~Entity();
/**
 * @brief The virtual move class, this is just an interface method which is
 *          overidden by the the entity classes.
 * @param _dir Direction of movement; Left or Right
 * @param _Id Identity of the object moving
 */

 virtual void move(Direction _dir = Direction::Left , EntityId _Id = EntityId::Cannon1) {};
/**
 * @brief The virtual stopMove class, this is just an interface method which is
 *          overidden by the the entity classes.
 * @param _dir Direction of movement; Left or Right
 * @param _Id Identity of the object moving
 */

 virtual void stopMove(Direction _dir = Direction::Left , EntityId _Id = EntityId::Cannon1) {};
 /**
  * @brief The  virtual update function is responsible for updating the position of Entity
  *         after movement is initiated.
  * @param elapsedTime time factor for mobement \distance \= \time \* \speed;
  */
 
 virtual void update(const float& elapsedTime = 0.0) {};
    /**
     * @brief Virtual function for setting texture of the object
     * @param _pos Firing position
     * @param orinetation Orientation the Aliens
     */
    
 virtual void setTexture(sf::Texture _texture, const int& _index = 0) {};
};

#endif // ENTITY_HPP
