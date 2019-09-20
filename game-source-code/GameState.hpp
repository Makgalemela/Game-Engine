#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include "Aliens.hpp"
#include "Cannon.hpp"

//****************************************************
//
// the class create and iniatialise game states
// 
// the class will be linked 
// 
//
//***************************************************

class GameState
{
public:
    GameState();
//        virtual void draw() = 0;
//        virtual void update() = 0;
//        virtual void inputHandler() = 0;
        
        
        bool GameOver(const Cannon& _cannon , const Aliens& _aliens) const;
    ~GameState();

};

#endif // GAMESTATE_HPP
