#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Cannon.hpp"
#include "SplashScreen.hpp"
#include "Aliens.hpp"
#include "Bullet.hpp"
#include "ResourceManager.hpp"
#include "collusion.hpp"
#include "Screen.hpp"
#include "GameState.hpp"


class Game : public Screen {
public:
    Game();
    void start();
    ~Game();

private:
    
    void gameLoop();
    void loadCannon(ResourceManager _rm);
    sf::RenderWindow _window;
    sf::Sprite _backgroundSprite;
    sf::Texture _backgroundTexture;
    SplashScreen _splash;
    Cannon _cannon;
    Aliens aliens;
    Bullet bullet;
    collusion _collide;
    DefenseBlocks _defense;
    sf::Vector2f _resolution;
    bool shotFired;
    sf::Sprite _GameOverSprite;
    sf::Texture _GameOverTexture;
    void input();
    void update(float dtAsSeconds);
    void draw();
    FiringDirection fd;
    bool gameOver;
    bool gamePlaying;
    sf::Clock _clock;
    GameState _gamestate;
};

#endif // GAME_HPP
