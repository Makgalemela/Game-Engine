#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Cannon.hpp"
#include "SplashScreen.hpp"
#include "Aliens.hpp"
#include "Bullet.hpp"
class Game
{
public:
    Game();
    void start();
    void gameLoop();
    ~Game();

private:
    
    sf::RenderWindow _window;
    sf::Sprite _backgroundSprite;
    sf::Texture _backgroundTexture;
    SplashScreen _splash;
    Cannon _cannon;
    Aliens aliens;
    Bullet bullet;
    void input();
    void update(float dtAsSeconds);
    void draw();
    ///void draw(const Aliens& aliens);

};

#endif // GAME_HPP
