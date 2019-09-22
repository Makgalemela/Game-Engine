#ifndef ENTITY_HPP
#define ENTITY_HPP


enum class Direction{
    
  Left = 0,
  Right  
};

enum class EntityId{
    Cannon1 = 0,
    Cannon2
};

class Entity
{
public:
    Entity();
    ~Entity();


 virtual void move(Direction _dir = Direction::Left , EntityId _Id = EntityId::Cannon1) {};
 virtual void stopMove(Direction _dir = Direction::Left , EntityId _Id = EntityId::Cannon1) {};
};

#endif // ENTITY_HPP
