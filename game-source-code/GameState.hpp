#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


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
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void inputHandler() = 0;
    ~GameState();

};

#endif // GAMESTATE_HPP
