#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/Game.hpp"
#include "../game-source-code/Aliens.hpp"
#include "../game-source-code/Cannon.hpp"
#include <SFML/Graphics.hpp>

TEST_CASE("Correct that correct number of enemie aliens is loaded")
{
    auto aliens = Aliens{};
    auto _alienContainer = aliens.aliensSpriteAlone();
    CHECK(54 == _alienContainer.size());
}


TEST_CASE("Cannon is able to move to the left")
{
     auto _cannon = Cannon{};
    auto _game = Game{};
    _game.Start();
    sf::Vector2f _position  = _cannon.getCannonCenterFirePosion();
    CHECK(_position.x < 100.f);
}


TEST_CASE("Cannon is able to move to the right")
{
    auto _cannon = Cannon{};
    auto _game = Game{};
    _game.Start();
    sf::Vector2f _position  = _cannon.getCannonCenterFirePosion();
    CHECK(_position.x > 500.f);
}


