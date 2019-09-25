#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/Game.hpp"
#include "../game-source-code/Aliens.hpp"
#include "../game-source-code/Cannon.hpp"
#include "../game-source-code/StopWatch.h"
#include "../game-source-code/ResourceManager.hpp"
#include "../game-source-code/Entity.hpp"
#include <string>
#include <SFML/Graphics.hpp>



// This section of tests test for the correct behaviour when loading the resources

//TEST_CASE("Throw Exception when Loading resources which do not exists")
//{
//    auto resources = ResourceManager{};
//    const std::string filename = "Laser_Cannon.png";
//    const std::string Exception = "Failed to load the resource at "+ filename;
//    CHECK_THROWS_AS(resources.loadResources(ResourceID::Default, filename), std::runtime_error(&Exception));
//}


TEST_CASE("No Exception throw when Loading resources which exist")
{
    auto resources = ResourceManager{};
    const std::string filename = "../executables/resources/bullet.png";
    CHECK_NOTHROW(resources.loadResources(ResourceID::Default, filename));
}


//This section test for the movents of aliens and the Cannon
TEST_CASE("Tests that the correct position is set")
{
    auto elapsedTime = 0.1f;
    auto expectedx = 300.f;
    auto expectedy = 220.f;
    auto resources = ResourceManager{};
    ///auto _watch = StopWatch{};
    auto cannon = Cannon{};
    const std::string filename = "../executables/resources/Laser_Cannon.png";
    resources.loadResources(ResourceID::Default, filename);
    cannon.setTexture(resources.get(ResourceID::LowerCannon),0);
    cannon.setInitPosOfCannon(sf::Vector2f(600, 250));
    cannon.update(elapsedTime);
    CHECK(cannon.getSprite().getPosition().x == expectedx);
    CHECK(cannon.getSprite().getPosition().y == expectedy);
}

TEST_CASE("Tests that the cannon can move left to right")
{
    auto elapsedTime = 0.1f;
    auto expected = 300.f + (elapsedTime*320.f);
    auto resources = ResourceManager{};
    ///auto _watch = StopWatch{};
    auto cannon = Cannon{};
    const std::string filename = "../executables/resources/Laser_Cannon.png";
    resources.loadResources(ResourceID::Default, filename);
    cannon.setTexture(resources.get(ResourceID::LowerCannon),0);
    cannon.setInitPosOfCannon(sf::Vector2f(600, 250));
     cannon.move(Direction::Right, EntityId::Cannon1);
    cannon.update(elapsedTime);
    CHECK(cannon.getSprite().getPosition().x == expected);
}


TEST_CASE("Tests that the cannon doesnot move up or down instead of right")
{
    auto elapsedTime = 0.1f;
    auto expected = 220;
    auto resources = ResourceManager{};
    ///auto _watch = StopWatch{};
    auto cannon = Cannon{};
    const std::string filename = "../executables/resources/Laser_Cannon.png";
    resources.loadResources(ResourceID::Default, filename);
    cannon.setTexture(resources.get(ResourceID::LowerCannon),0);
    cannon.setInitPosOfCannon(sf::Vector2f(600, 250));
    cannon.move(Direction::Right, EntityId::Cannon1);
    cannon.update(elapsedTime);
    CHECK(cannon.getSprite().getPosition().y == expected);
}

TEST_CASE("Tests that the cannon can move right to left")
{
    auto elapsedTime = 0.1f;
    auto expected = 300.f - (elapsedTime*320.f);
    auto resources = ResourceManager{};
    auto cannon = Cannon{};
    const std::string filename = "../executables/resources/Laser_Cannon.png";
    resources.loadResources(ResourceID::Default, filename);
    cannon.setTexture(resources.get(ResourceID::LowerCannon),0);
    cannon.setInitPosOfCannon(sf::Vector2f(600, 250));
     cannon.update(elapsedTime);
    cannon.move(Direction::Left , EntityId::Cannon1);
    cannon.update(elapsedTime);
    cannon.update(elapsedTime);
    cannon.stopMove(Direction::Left , EntityId::Cannon1);
    CHECK(cannon.getSprite().getPosition().x == expected);
}