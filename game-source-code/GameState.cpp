#include "GameState.hpp"

GameState::GameState()
{


}



bool GameState::GameOver(const Cannon& _cannon , const Aliens& _aliens) const{
    
    if(_cannon.getCannonLives() == 0 || _aliens.aliensAtBottonOrTop() ||
            _aliens.allAliensKilled()) return true;
        return false;
}
GameState::~GameState()
{
}

