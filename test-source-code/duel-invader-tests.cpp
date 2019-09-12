#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/Game.hpp"
#include "../game-source-code/Aliens.hpp"
#include "../game-source-code/Cannon.hpp"
#include <SFML/Graphics.hpp>



//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////Test For Aliens and their behaviour /////////////////////
////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Correct number of aliens are loaded")
{
    auto aliens = Aliens{};
    aliens.loadAliens();
    auto _alienContainer = aliens.aliensSpriteAlone();
    CHECK(54 == _alienContainer.size());
}


TEST_CASE("The aliens start at the correct positions")
{
    auto aliens = Aliens{};
    sf::Vector2f _pos;
    _pos.x = 460.f;
    _pos.y = 230.f;
    auto[alien,aliensu, _position, _positionu] = aliens.aliensSprite();
    CHECK(_positionu.x == _pos.x);
    CHECK( _positionu.y == _pos.y);
    _pos.x = 5.f;
    _pos.y = 310.f;
    CHECK(_position.x == _pos.x);
    CHECK( _position.y == _pos.y);
}



