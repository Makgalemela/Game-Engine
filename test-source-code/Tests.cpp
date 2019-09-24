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
    CHECK(30 == _alienContainer.size());
    CHECK(30 == _alienContainer.size());
}